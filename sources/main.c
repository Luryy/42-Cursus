/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:11:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/11 21:05:20 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	start_struct(t_all *all, t_map *map)
{
	all->map = map;
	all->whatever = 0;
	map->qt_col = 0;
	map->qt_line = 1;
	map->qt_arq = 0;
}

int	main(int argc, char **argv)
{
	t_all	all;
	t_map	map;

	start_struct(&all, &map);
	check_map(&all, argc, argv);
	return (1);
}
