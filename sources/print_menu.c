/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_menu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 18:03:40 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/18 13:58:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	print_menu(t_dot param)
{
	char	*menu;

	menu = "up, down, left, right: move picture";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 15, C_GREEN, menu);
	menu = "space: switch projections; +, -: zoom";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 30, C_GREEN, menu);
	menu = "1,2: z-scale; 8, 9: rotation";
	mlx_string_put(param.mlx_ptr, param.win_ptr, 10, 45, C_GREEN, menu);
}
