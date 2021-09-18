/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:25:24 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/18 10:48:42 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	set_default(t_dot *param)
{
	param->scale = 20;
	param->z_scale = 1;
	param->is_isometric = 1;
	param->angle = 0.523599;
	param->win_x = 2000;
	param->win_y = 1000;
	param->shift_x = param->win_x / 3;
	param->shift_y = param->win_y / 3;
	param->mlx_ptr = mlx_init();
	param->win_ptr =\ 
	mlx_new_window(param->mlx_ptr, param->win_x, param->win_y, "FDF");
}

int	main(int argc, char **argv)
{
	t_dot	**matrix;

	if (argc == 2)
	{
		matrix = read_map(*++argv);
		set_default(&matrix[0][0]);
		draw(matrix);
		mlx_key_hook(matrix[0][0].win_ptr, deal_key, matrix);
		mlx_loop(matrix[0][0].mlx_ptr);
	} else {
		ft_error("Incorrect params");
	}
	return (1);
}
