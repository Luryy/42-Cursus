/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:11:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/11 20:17:34 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	start_struct(t_all *all, t_map *map)
{
	all->whatever = 0;
	map->qt_col = 0;
	map->qt_line = 0;
}

int	main(int argc, char **argv)
{
	t_all	all;
	t_map	map;

	start_struct(&all, &map);
	check_map(&all, argc, argv);
	return (1);
}
