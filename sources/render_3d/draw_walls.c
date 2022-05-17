/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:16:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/17 20:44:20 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_items(t_all *all, int i, int line_offset, int line_hight)
{
	int		j;

	j = -1;
	while (++j < all->mlx_info->win_y - all->mlx_info->win_y / 3)
	{
		if (j <= line_offset)
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, all->texture->c);
		else if (j > line_offset && j < line_hight + line_offset)
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, 255);
		else
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, all->texture->f);
	}
}

float	get_dist(t_all *all, int angle)
{
	float	i;
	float	j;
	int		x;
	int		y;

	i = 0;
	x = all->map->user_x;
	y = all->map->user_y;
	j = ((float)angle / 15) - 30;
	while (all->map->all_map[y][x] != '1')
	{
		x = all->map->user_x + i * sin((all->map->user_view - j) * PI / 180);
		y = all->map->user_y + i * cos((all->map->user_view - j) * PI / 180);
		i += 0.005;
	}
	return (i * cos(j * PI / 180));
}

void	draw_walls(t_all *all)
{
	int		i;
	float	wall_dist;
	int		line_hight;
	int		line_offset;

	i = -1;
	while (++i < all->mlx_info->win_x)
	{
		wall_dist = get_dist(all, i);
		line_hight = 400 / wall_dist;
		if (line_hight > 400)
			line_hight = 400;
		 line_offset = 200 - line_hight / 2;
		draw_items(all, i, line_offset, line_hight);
	}
}
