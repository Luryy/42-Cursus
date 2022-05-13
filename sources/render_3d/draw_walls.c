/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:16:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/12 23:11:04 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

float	get_dist(t_all *all, int angle)
{
	float	i;
	float	j;
	int		x;
	int		y;

	i = 0;
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
	int		j;
	float	wall_dist;
	int		line_hight;
	int		line_offset;

	i = -1;
	while (++i < all->mlx_info->win_x)
	{
		j = -1;
		wall_dist = get_dist(all, i);
		line_hight = 400 / wall_dist;
		if (line_hight > 400)
			line_hight = 400;
		line_offset = 200 - line_hight / 2;
		while (++j < line_hight)
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j + line_offset, 0x0000FF);
	}
}
