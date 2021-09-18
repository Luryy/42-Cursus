/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:59:50 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/18 12:55:05 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	command_keys(int key, t_dot **matrix)
{
	if (key == KMORE)
		matrix[0][0].scale += 3;
	else if (key == KLESS)
		matrix[0][0].scale -= 3;
	else if (key == K1)
		matrix[0][0].z_scale += 1;
	else if (key == K2)
		matrix[0][0].z_scale -= 1;
	else if (key == KSPACE)
		matrix[0][0].is_isometric = !matrix[0][0].is_isometric;
	else if (key == K8)
		matrix[0][0].angle += 0.05;
	else if (key == K9)
		matrix[0][0].angle -= 0.05;
	else
		return ;
	mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
	print_menu(matrix[0][0]);
	draw(matrix);
}

int	deal_key(int key, t_dot **matrix)
{
	command_keys(key, matrix);
	if (key == KLEFT || key == KUP || key == KDOWN || key == KRIGHT)
		move(key, matrix);
	if (key == KESC)
	{
		mlx_destroy_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
		free(matrix);
		exit(0);
	}
	return (0);
}
