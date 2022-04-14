/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_struct.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:14:03 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/13 22:53:21 by lyuri-go         ###   ########.fr       */
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

int	validate_map_char(char **all_map)
{
	int	counter_line;
	int	counter_col;

	counter_line = 0;
	counter_col = 0;
	while (all_map[counter_line][0] != '\0')
	{
		while (all_map[counter_line][counter_col] != '\0')
		{
			if (!is_valid_char(all_map[counter_line][counter_col]))
			{
				printf("Invalid map\n");
				return (0);
			}
			counter_col++;
		}
		counter_col = 0;
		counter_line++;
	}
	return (1);
}

int	parse_map(t_all *all, int fd1)
{
	int	i;

	i = 0;
	while (get_next_line(fd1, &all->map->all_map[i]))
		i++;
	if (!validate_map_char(&all->map->all_map[8]))
		return (0);
	return (1);
}
