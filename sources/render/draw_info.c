/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:56:31 by rarodrig          #+#    #+#             */
/*   Updated: 2022/05/25 22:16:02 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	draw_info(t_all *all)
{
	int		map_win_x;
	int		map_win_y;
	void	*image;

	image = mlx_xpm_file_to_image(all->mlx_info->mlx_ptr,
			"./textures/teste.xpm", &map_win_x, &map_win_y);
	if (image)
	{
		mlx_put_image_to_window(all->mlx_info->mlx_ptr, all->mlx_info->win_ptr,
			image, 300, 400);
	}
}
