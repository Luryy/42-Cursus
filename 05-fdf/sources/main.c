/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:25:24 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/21 19:53:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_default(t_win *param)
{
	param->scale = INIT_SCALE;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = INIT_ANGLE;
	param->win_x = X_WIN_SIZE;
	param->win_y = Y_WIN_SIZE;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(
			param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;
	t_win	*winfo;
	t_var	var;

	winfo = (t_win *)malloc(sizeof(t_win));
	var.dot = &matrix;
	var.winfo = &winfo;
	if (argc == 2)
	{
		matrix = read_map(*++argv);
		set_default(winfo);
		draw(matrix, winfo);
		mlx_key_hook(winfo->win_ptr, deal_key, &var);
		mlx_loop(winfo->mlx_ptr);
	}
	else
	{
		errno = 5;
		ft_error("Incorrect params");
	}
	return (1);
}
