/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:14:03 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/12 22:53:28 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	validate_map_char(t_map *map, char **all_map)
{
	int	counter_line;
	int	counter_col;

	counter_line = 1;
	counter_col = 0;
	while (counter_line != map->qt_line)
	{
		if (all_map[counter_line][counter_col] != '1' &&
		(all_map[counter_line][counter_col] != '0' &&
		(all_map[counter_line][counter_col]) != 'N') &&
		all_map[counter_line][counter_col] != 'S' &&
		(all_map[counter_line][counter_col] != 'E' &&
		all_map[counter_line][counter_col] != 'W'))
		{
			printf("Mapa Inválido\n");
			return (0);
		}
		if (counter_col == map->qt_col - 1)
		{
			counter_line++;
			counter_col = 0;
		}
		counter_col++;
	}
	return (1);
}

int	populate_map_var(t_map *map, int fd1)
{
	int	i;

	i = 0;
	fd1 = open(map->path_map, O_RDONLY);
	map->all_map = malloc(sizeof(char **) * map->qt_line - 1);
	if (!map->all_map)
		return (0);
	while (get_next_line(fd1, &map->all_map[i++]))
		;
	if (!validate_map_char(map, map->all_map))
		return (0);
	close(fd1);
	return (1);
}

int	cont_col(t_map *map, int fd1)
{
	char	buffer;
	int		size;

	while (true)
	{
		size = read(fd1, &buffer, 1);
		if (buffer == '\n')
			break ;
		if (buffer != '\n')
			map->qt_col++;
	}
	if (map->qt_col < 5)
	{
		printf("Error de colunas \n");
		return (0);
	}
	size = 1;
	return (size);
}

int	cont_line(t_map *map, int fd1)
{
	int		size;
	char	buffer;

	fd1 = open(map->path_map, O_RDONLY);
	while (true)
	{
		size = read(fd1, &buffer, 1);
		if (buffer == '\n')
			map->qt_line++;
		if (buffer != '\n' && size > 0)
			map->qt_arq++;
		if (size == 0)
			break ;
	}
	if (map->qt_line < 4)
	{
		printf("Error de linhas\n");
		return (0);
	}
	close(fd1);
	return (1);
}

int	map_struct(t_map *map, int fd1)
{
	if (!fd1)
		return (0);
	if (!cont_line(map, fd1))
		return (0);
	if (!cont_col(map, fd1))
		return (0);
	if (!populate_map_var(map, fd1))
		return (0);
	printf("mapa valido\n");
	return (1);
}
