/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_window_size.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:06:17 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/18 12:25:53 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	check_win_size(int key, t_dot **matrix)
{
	if ((key == KUP && matrix[0][0].shift_y <= 100) ||
	(key == KLEFT && matrix[0][0].shift_x <= 100))
		return (1);
	if ((key == KDOWN && matrix[0][0].shift_y > Y_WIN_SIZE - 100) ||
	(key == KRIGHT && matrix[0][0].shift_x > X_WIN_SIZE - 500))
		return (1);
	return (0);
}

void	move(int key, t_dot **matrix)
{
	if (check_win_size(key, matrix))
		return ;
	if (key == KLEFT)
		matrix[0][0].shift_x -= 10;
	if (key == KRIGHT)
		matrix[0][0].shift_x += 10;
	if (key == KUP)
		matrix[0][0].shift_y -= 10;
	if (key == KDOWN)
		matrix[0][0].shift_y += 10;
	mlx_clear_window(matrix[0][0].mlx_ptr, matrix[0][0].win_ptr);
	draw(matrix);
	mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
	mlx_loop(matrix[0][0].mlx_ptr);
}
