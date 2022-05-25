/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:11:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/24 21:08:05 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	start_struct(t_all *all, t_map *map, t_texture *texture, t_mlx *mlx)
{
	t_square	square;

	all->square = &square;
	all->map = map;
	all->texture = texture;
	all->mlx_info = mlx;
	mlx->win_x = 900;
	mlx->win_y = 600;
	map->all_map = malloc(300 * sizeof(char *));
	all->map->user_x = -1;
	all->texture->n = NULL;
	all->texture->w = NULL;
	all->texture->e = NULL;
	all->texture->s = NULL;
	all->texture->f = NULL;
	all->texture->c = NULL;
	all->square->col = 0;
	all->square->line = 0;
	all->square->color = 0;
}

int	main(int argc, char **argv)
{
	t_all			all;
	t_map			map;
	t_texture		texture;
	t_mlx			mlx_info;
	int				fd1;

	start_struct(&all, &map, &texture, &mlx_info);
	fd1 = find_map(&all, argc, argv[1]);
	parse_map(&all, fd1);
	render(&mlx_info, &all);
	ft_free(&all);
	return (0);
}
