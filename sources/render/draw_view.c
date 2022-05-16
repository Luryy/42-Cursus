/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_view.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:17:31 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/14 18:37:39 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_heaven(t_all *all)
{
	int		y;
	int		i;
	int		j;
	float	wall_dist;
	int		line_hight;
	int		line_offset;

	i = -1;
	y = 0;
	while (++i < all->mlx_info->win_x)
	{
		j = -1;
		wall_dist = get_dist(all, i);
		line_hight = 400 / wall_dist;
		if (line_hight > 400)
			line_hight = 400;
		 line_offset = 200 - line_hight / 2;
		while (++j < line_offset)
			my_mlx_pixel_put(&all->mlx_info->view, i,
				j, "./brick.xpm");
	}
}

void	init_view(t_mlx *mlx, t_img *img, t_all *all)
{
	img->img = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y - mlx->win_y / 3);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	draw_heaven(all);
	draw_walls(all);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, img->img, 0, 0);
}
