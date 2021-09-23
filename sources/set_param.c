/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 17:57:53 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/20 20:56:30 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	zoom(t_dot *a, t_dot *b, t_win *winfo)
{
	a->x *= winfo->scale;
	a->y *= winfo->scale;
	b->x *= winfo->scale;
	b->y *= winfo->scale;
	a->z *= winfo->z_scale;
	b->z *= winfo->z_scale;
}

void	set_param(t_dot *a, t_dot *b, t_win *winfo)
{
	zoom(a, b, winfo);
	if (winfo->is_isometric)
	{
		isometric(a, winfo->angle);
		isometric(b, winfo->angle);
	}
	a->x += winfo->shift_x;
	a->y += winfo->shift_y;
	b->x += winfo->shift_x;
	b->y += winfo->shift_y;
}
