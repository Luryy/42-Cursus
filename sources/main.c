/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:11:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/12 22:48:13 by rarodrig         ###   ########.fr       */
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
	int		fd1;

	start_struct(&all, &map);
	fd1 = find_map(&map, argc, argv[1]);
	if (fd1 == 0)
		return (0);
	if (!map_struct(all.map, fd1))
		return (0);
	return (1);
}
