/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:25:55 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/11 21:59:51 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_lines(t_all *all, int x, int y, int color)
{
	int	i;
	int	angle;

	angle = -30;
	while (angle < 30)
	{
		i = 0;
		while (convert_pixel_to_position(all,
				x + i * sin((all->map->user_view + angle) * PI / 180),
				y + i * cos((all->map->user_view + angle) * PI / 180)) != '1')
		{
			my_mlx_pixel_put(&all->mlx_info->map,
				x + i * sin((all->map->user_view + angle) * PI / 180),
				y + i * cos((all->map->user_view + angle) * PI / 180), color);
			i++;
		}
		all->map->wall_distances[angle + 30] = i;
		angle++;
	}
}

void	border(t_img *img, int x, int y, int color)
{
	int	i;

	i = -1;
	while (++i <= y)
		my_mlx_pixel_put(img, x - 1, i, color);
	i = -1;
	while (++i < y)
		my_mlx_pixel_put(img, 0, i, color);
	i = -1;
	while (++i <= x)
		my_mlx_pixel_put(img, i, y - 1, color);
	i = -1;
	while (++i < x)
		my_mlx_pixel_put(img, i, 0, color);
}

void	square(t_img *img, int x, int y, int color, int line, int col)/* trocar numero de funções */
{
	int	i;
	int	j;

	i = line - 1;
	while (++i <= x + line)
	{
		j = col - 1;
		while (++j <= y + col)
			my_mlx_pixel_put(img, i, j, color);
	}
}
