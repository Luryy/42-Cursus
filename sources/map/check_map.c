/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:43:14 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/11 22:59:36 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	populate_map_var(t_map *map, char *argv)
{
	int	fd1;
	int	i;

	i = 0;
	map->all_map = malloc(sizeof(char **) * map->qt_line - 1);
	if (!map->all_map)
		return (0);
	fd1 = open(argv, O_RDONLY);
	//criar free do mapa
	while (get_next_line(fd1, &map->all_map[i++]))
		;
	if (!validate_map_char(map, map->all_map))
		return (0);
	return (1);
}

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
		{
			printf("Extensão do mapa inválido\n");
			return (0);
		}
	}
	return (1);
}

int	check_map(t_all *all, int argc, char **argv)
{
	if (argc == 1)
	{
		printf("ERROR!! Input need some map .cub\n");
		return (0);
	}
	if (argc > 2)
		printf("Will be utilized the first file\n");
	if (!check_extension(argv[1], ".cub"))
		return (0);
	if (!map_struct(all->map, argv[1]))
		return (0);
	populate_map_var(all->map, argv[1]);
	printf("map okay");
	return (1);
}
