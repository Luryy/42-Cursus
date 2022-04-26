/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:14:03 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/25 20:59:26 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_valid_char(char character)
{
	if (character != '1' && character != '0'
		&& character != 'N' && character != 'S'
		&& character != 'E' && character != ' '
		&& character != 'W')
		return (0);
	return (1);
}

int	validate_map_char(t_map *map)
{
	int	counter_line;
	int	counter_col;

	counter_line = 8;
	counter_col = 0;
	while (map->all_map[counter_line][0] != '\0')
	{
		while (map->all_map[counter_line][counter_col] != '\0')
		{
			if (!is_valid_char(map->all_map[counter_line][counter_col]))
			{
				printf("Invalid map\n");
				return (1);
			}
			counter_col++;
		}
		counter_col = 0;
		counter_line++;
	}
	map->quant_line = counter_line - 1;
	return (0);
}

int	parse_map(t_all *all, int fd1)
{
	int	i;

	i = 0;
	while (get_next_line(fd1, &all->map->all_map[i]))
		i++;
	if (validate_map_char(all->map))
		return (1); //Ajustar Exiter
	if (validate_map_struct(all->map))
		exiter(all, EXIT_FAILURE);
	return (0);
}
