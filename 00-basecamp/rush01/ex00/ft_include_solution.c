/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include_solution.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 21:17:19 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:06:56 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_include_solution_i(int i, int j, int **solution, int ***mp)
{
	if (i < 4)
	{
		ft_solution_matrix(j, i, 4, solution);
		ft_clear_solution(j, i, 4, mp);
	}
	else
	{
		i = i - 4;
		ft_solution_matrix(i, j, 4, solution);
		ft_clear_solution(i, j, 4, mp);
	}
}

void	ft_include_solution_n(int i, int *vec, int **solution, int ***mp)
{
	int j;

	j = -1;
	if (i < 4)
	{
		while (++j < 4)
		{
			ft_solution_matrix(j, i, vec[j], solution);
			ft_clear_solution(j, i, vec[j], mp);
		}
	}
	else
	{
		i = i - 4;
		while (++j < 4)
		{
			ft_solution_matrix(i, j, vec[j], solution);
			ft_clear_solution(i, j, vec[j], mp);
		}
	}
}
