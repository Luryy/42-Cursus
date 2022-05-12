/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 21:16:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/11 22:22:28 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_walls(t_all *all)
{
	int	i;
	int	j;
	int	k;
	int	wall_size;

	i = -1;
	wall_size = all->mlx_info->win_x / 60;
	while (++i < 60)
	{
		k = -1;
		while (++k < wall_size)
		{
			j = -1;
			while (++j < all->map->wall_distances[60 - i])
				my_mlx_pixel_put(&all->mlx_info->view,
					i * wall_size + k, j, 0x00FFFF);
		}
	}
}
