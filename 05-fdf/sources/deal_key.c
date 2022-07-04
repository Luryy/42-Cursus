/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:59:50 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/20 21:46:16 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	command_keys(int key, t_dot **matrix, t_win *winfo)
{
	if (key == KMORE)
		winfo->scale += 3;
	else if (key == KLESS)
		winfo->scale -= 3;
	else if (key == K1)
		winfo->z_scale += 1;
	else if (key == K2)
		winfo->z_scale -= 1;
	else if (key == KSPACE)
		winfo->is_isometric = !winfo->is_isometric;
	else if (key == K8)
		winfo->angle += 0.05;
	else if (key == K9)
		winfo->angle -= 0.05;
	else
		return ;
	mlx_clear_window(winfo->mlx_ptr, winfo->win_ptr);
	print_menu(winfo);
	draw(matrix, winfo);
}

int	deal_key(int key, t_var *var)
{
	command_keys(key, *(var->dot), *(var->winfo));
	if (key == KLEFT || key == KUP || key == KDOWN || key == KRIGHT)
		move(key, *(var->dot), *(var->winfo));
	if (key == KESC)
	{
		mlx_destroy_window((*(var->winfo))->mlx_ptr, (*(var->winfo))->win_ptr);
		free(*(var->winfo));
		exit(0);
	}
	return (0);
}
