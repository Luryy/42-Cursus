/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_struct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:14:03 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/11 20:24:47 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	cont_line(t_map *map, int fd1)
{
	int		size;
	char	buffer;

	while (true)
	{
		size = read(fd1, &buffer, 1);
		if (buffer == '\n')
			map->qt_line++;
		if (buffer != '\n' && size > 0)
			map->qt_arq++;
	}
	if (map->qt_line < 4)
	{
		printf("Error de linhas\n");
		return (0);
	}
	printf("Lines = %d\n", map->qt_line);
	close(fd1);
	return (1);
}

int	cont_col(t_map *map, char *argv)
{
	char	buffer;
	int		fd1;

	fd1 = open(argv, O_RDONLY);
	while (true)
	{
		read(fd1, &buffer, 1);
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
	close(fd1);
	return (1);
}

int	map_struct(t_map *map, char *argv)
{
	int	fd1;

	fd1 = open(argv, O_RDONLY);
	if (!fd1)
		return (0);
	if (!cont_line(map, fd1))
		return (0);
	if (!cont_col(map, argv))
		return (0);
	return (1);
}
