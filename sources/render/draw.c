/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 21:25:55 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/05 22:32:29 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_line(t_img *img, int x, int y, int color)
{
	int	i;

	i = -1;
	while (++i <= 20)
		my_mlx_pixel_put(img, x, y + i, color);
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
