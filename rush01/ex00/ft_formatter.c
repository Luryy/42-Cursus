/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_formatter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:01:15 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:07:04 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_format_i(int d, int l, int **solution, int ***mp)
{
	if (l == 0)
		ft_include_solution_i(d, 0, solution, mp);
	else if (l == 1)
		ft_include_solution_i(d, 3, solution, mp);
}

void	ft_format_n(int d, int l, int **solution, int ***mp)
{
	int vec[4];

	if (l == 0)
	{
		vec[0] = 1;
		vec[1] = 2;
		vec[2] = 3;
		vec[3] = 4;
	}
	else if (l == 1)
	{
		vec[0] = 4;
		vec[1] = 3;
		vec[2] = 2;
		vec[3] = 1;
	}
	ft_include_solution_n(d, vec, solution, mp);
}

void	ft_format_m_up(int d, int view, int ***mp)
{
	int clear_value;
	int clear_index;

	clear_index = -1;
	if (d < 4)
	{
		while (++clear_index < 4)
		{
			clear_value = 4 - view + 2 + clear_index - 1;
			while (++clear_value < 4)
				ft_clear_value(clear_index, d, clear_value, mp);
		}
	}
	else
	{
		while (++clear_index < 4)
		{
			clear_value = 4 - view + 2 + clear_index - 1;
			while (++clear_value < 4)
				ft_clear_value(d - 4, clear_index, clear_value, mp);
		}
	}
}

void	ft_format_m_down(int d, int view, int ***mp)
{
	int clear_value;
	int clear_index;

	clear_index = 4;
	if (d < 4)
	{
		while (--clear_index > -1)
		{
			clear_value = 4 - view + 2 - clear_index + 3 - 1;
			while (++clear_value < 4)
				ft_clear_value(clear_index, d, clear_value, mp);
		}
	}
	else
	{
		while (--clear_index > -1)
		{
			clear_value = 4 - view + 2 - clear_index + 3 - 1;
			while (++clear_value < 4)
				ft_clear_value(d - 4, clear_index, clear_value, mp);
		}
	}
}

void	ft_format_m(int d, int l, int view, int ***mp)
{
	if (l == 0)
	{
		ft_format_m_up(d, view, mp);
	}
	else if (l == 1)
	{
		ft_format_m_down(d, view, mp);
	}
}
