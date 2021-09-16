/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:54:11 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/16 19:23:02 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_color(t_dot a, t_dot b, int *color)
{
	if (b.z != a.z)
		*color = 0xfc031c;
	else if (b.z || a.z)
		*color = 0xfc0345;
	else
		*color = 0xBBFAFF;
}

float	fmodule(float i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

void	line(t_dot a, t_dot b, t_dot *param)
{
	float	step_x;
	float	step_y;
	float	max;
	int		color;

	set_param(&a, &b, param);
	step_x = b.x - a.x;
	step_y = b.y - a.y;
	max = fmodule(step_x);
	if (fmodule(step_x) < fmodule(step_y))
		max = fmodule(step_y);
	step_x /= max;
	step_y /= max;
	set_color(a, b, &color);
	while ((int)(a.x - b.x) || (int)(a.y - b.y))
	{
		mlx_pixel_put(param->mlx_ptr, param->win_ptr, a.x, a.y, color);
		a.x += step_x;
		a.y += step_y;
		if (a.x > param->win_x || a.y > param->win_y || a.y < 0 || a.x < 0)
			break ;
	}
}

void	draw(t_dot **matrix)
{
	int		y;
	int		x;

	print_menu(matrix[0][0]);
	y = 0;
	while (matrix[y])
	{
		x = 0;
		while (1)
		{
			if (matrix[y + 1])
				line(matrix[y][x], matrix[y + 1][x], &matrix[0][0]);
			if (!matrix[y][x].is_last)
				line(matrix[y][x], matrix[y][x + 1], &matrix[0][0]);
			if (matrix[y][x].is_last)
				break ;
			x++;
		}
		y++;
	}
}
