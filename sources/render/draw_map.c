/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:23:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/27 23:18:32 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_map2d(t_all *all, t_img *img, int map_win_x, int map_win_y)
{
	int	i;
	int	j;
	int	map_width;
	int	map_hight;

	map_width = map_win_x / all->map->quant_max_col;
	map_hight = map_win_y / (all->map->quant_line - 7);
	i = 7;
	while (++i <= all->map->quant_line)
	{
		j = -1;
		while (all->map->all_map[i][++j] != '\0')
		{
			if (all->map->all_map[i][j] == '1')
				square(img, map_width, map_hight, 0xFFFFFF00, j * map_width, (i - 8) * map_hight);
			else if (all->map->all_map[i][j] == '0')
				square(img, map_width, map_hight, 0xFFFF0000, j * map_width, (i - 8) * map_hight);
		}
	}
}

void	init_map(t_mlx *mlx, t_img *img, t_all *all)
{
	int	map_win_x;
	int	map_win_y;

	map_win_x = mlx->win_x / 3;
	map_win_y = mlx->win_y / 3;
	img->img = mlx_new_image(mlx->mlx_ptr, map_win_x, map_win_y);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	border(img, map_win_x, map_win_y, 0x00FF0000);
	print_map2d(all, img, map_win_x, map_win_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		img->img, 0, mlx->win_y - map_win_y);
}
