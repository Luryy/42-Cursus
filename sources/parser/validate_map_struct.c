/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:49:27 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/25 21:09:27 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_around(t_map *map, int count_line, int count_col)
{
	if (map->all_map[count_line - 1][count_col] == ' ' || count_line - 1 < 8)
		return (1);
	if (map->all_map[count_line + 1][count_col] == ' ' ||
		map->quant_line == count_line)
		return (1);
	if (map->all_map[count_line][count_col - 1] == ' ' || count_col - 1 < 0)
		return (1);
	if (map->all_map[count_line][count_col + 1] == ' ' ||
		map->all_map[count_line][count_col + 1] == '\0')
		return (1);
	return (0);
}

int	validate_map_struct(t_map *map)
{
	int	count_line;
	int	count_col;

	count_line = 8;
	count_col = 0;
	while (map->all_map[count_line][count_col] != '\0')
	{
		while (map->all_map[count_line][count_col] != '\0')
		{
			if (map->all_map[count_line][count_col] != '1' &&
				map->all_map[count_line][count_col] != ' ')
			{
				if (check_around(map, count_line, count_col))
				{
					printf("Invalid Map, It must be surrounded by walls\n");
					return (1);
				}
			}
			count_col++;
		}
		count_col = 0;
		count_line++;
	}
	return (0);
}
