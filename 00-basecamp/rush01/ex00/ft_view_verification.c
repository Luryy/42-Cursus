/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_verification.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:38:08 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:05:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_check_dimenssion(int *view, int dimension, int **solution, int ***mp)
{
	int l;

	l = -1;
	while (++l < 2)
	{
		if (view[l] == 4)
			ft_format_n(dimension, l, solution, mp);
		else if (view[l] == 1)
			ft_format_i(dimension, l, solution, mp);
		else if (1 < view[l] && view[l] < 4)
			ft_format_m(dimension, l, view[l], mp);
	}
}

void	ft_view_verification(int **views, int **solution, int ***mp)
{
	int d;

	d = -1;
	while (++d < 8)
	{
		ft_check_dimenssion(views[d], d, solution, mp);
	}
}
