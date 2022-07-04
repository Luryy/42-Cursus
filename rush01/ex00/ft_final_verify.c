/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_final_verify.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:14:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:07:11 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	ft_verify_dimension(int d, int l, int value, int **solution)
{
	int is_wrong;
	int count_value;

	is_wrong = 0;
	if (d < 4)
	{
		if (l == 0)
			count_value = ft_count_coloumn_view_start(d, solution);
		else
			count_value = ft_count_coloumn_view_end(d, solution);
	}
	else
	{
		if (l == 0)
			count_value = ft_count_line_view_start(d - 4, solution);
		else
			count_value = ft_count_line_view_end(d - 4, solution);
	}
	if (count_value != value)
		is_wrong = 1;
	return (is_wrong);
}

int	ft_final_verify(int **view, int **solution)
{
	int i;
	int ok;

	i = -1;
	ok = 1;
	while (++i < 8)
	{
		ok -= ft_verify_dimension(i, 0, view[i][0], solution);
		ok -= ft_verify_dimension(i, 1, view[i][1], solution);
	}
	return (ok);
}
