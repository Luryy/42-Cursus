/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:23:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/09 22:16:02 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	print_user2d(t_all *all, t_img *img, int map_win_x, int map_win_y)
{
	int	map_width;
	int	map_hight;
	int	user_x;
	int	user_y;

	map_width = map_win_x / all->map->quant_max_col;
	map_hight = map_win_y / (all->map->quant_line - 7);
	user_x = all->map->user_x * map_width;
	user_y = (all->map->user_y - 8) * map_hight;
	square(img, map_width / 3, map_hight / 3, 0xFFFF00, user_x - map_width / 6, user_y - map_hight / 6);
	draw_lines(all, user_x, user_y, 0xFFFF00);
}

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
				square(img, map_width, map_hight, 0xFFFFFF,
					j * map_width, (i - 8) * map_hight);
			else if (all->map->all_map[i][j] == '0'
				|| all->map->all_map[i][j] == 'N'
				|| all->map->all_map[i][j] == 'W'
				|| all->map->all_map[i][j] == 'S'
				|| all->map->all_map[i][j] == 'E')
				square(img, map_width, map_hight, 0x000000,
					j * map_width, (i - 8) * map_hight);
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
	print_user2d(all, img, map_win_x, map_win_y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		img->img, 0, mlx->win_y - map_win_y);
}
