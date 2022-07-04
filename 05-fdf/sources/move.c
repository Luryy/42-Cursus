/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:06:17 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/20 21:55:11 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	check_win_size(int key, t_win *winfo)
{
	if ((key == KUP && winfo->shift_y <= 100)
		|| (key == KLEFT && winfo->shift_x <= 100))
		return (1);
	if ((key == KDOWN && winfo->shift_y > Y_WIN_SIZE - 100)
		|| (key == KRIGHT && winfo->shift_x > X_WIN_SIZE - 500))
		return (1);
	return (0);
}

void	move(int key, t_dot **matrix, t_win *winfo)
{
	t_var	var;

	var.dot = &matrix;
	var.winfo = &winfo;
	if (check_win_size(key, winfo))
		return ;
	if (key == KLEFT)
		winfo->shift_x -= 10;
	if (key == KRIGHT)
		winfo->shift_x += 10;
	if (key == KUP)
		winfo->shift_y -= 10;
	if (key == KDOWN)
		winfo->shift_y += 10;
	mlx_clear_window(winfo->mlx_ptr, winfo->win_ptr);
	draw(matrix, winfo);
	mlx_key_hook(winfo->win_ptr, deal_key, &var);
	mlx_loop(winfo->mlx_ptr);
}
