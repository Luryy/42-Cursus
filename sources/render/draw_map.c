/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 20:23:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/03 22:19:06 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put_2(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	square_user(t_img *img, int x, int y, int color, int line, int col)/* trocar numero de funções */
{
	int		i;
	int		j;

	i = line - 1;
	while (++i <= x + line)
	{
		j = col - 1;
		while (++j <= y + col)
		{
			printf("here\n");
			my_mlx_pixel_put_2(img, i, j, color);
		}
	}
}

static void	print_user2d(t_all *all, t_img *img, int map_win_x, int map_win_y)
{
	int	map_width;
	int	map_hight;

	map_width = map_win_x / all->map->quant_max_col;
	map_hight = map_win_y / (all->map->quant_line - 7);
	printf("user = %f\n", all->map->user_y);
	printf("teste 1 = %f\n teste 2 = %f\n", all->map->user_x * map_width, (all->map->user_y - 8) * map_hight);
	square_user(img, map_width / 3, map_hight / 3, 0xFFFF00, all->map->user_x * map_width, (all->map->user_y - 8) * map_hight);
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
