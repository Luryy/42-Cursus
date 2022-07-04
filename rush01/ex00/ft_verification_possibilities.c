/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verification_possibilities.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:33:50 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 23:14:58 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_set_params(int *is_alone, int *undone)
{
	*is_alone = 0;
	*undone = 1;
}

int		ft_verification(int ***m, int **solution, int i, int j)
{
	int k;
	int current_value;
	int is_alone;
	int undone;

	is_alone = 1;
	current_value = 0;
	k = -1;
	undone = 0;
	while (++k < 4)
	{
		if (m[i][j][k] != 0 && current_value == 0)
			current_value = m[i][j][k];
		else if (m[i][j][k] != 0 && m[i][j][k] != current_value)
			ft_set_params(&is_alone, &undone);
		if (k == 3)
			if (is_alone == 1)
			{
				ft_clear_solution(i, j, current_value, m);
				ft_solution_matrix(i, j, current_value, solution);
			}
	}
	return (undone);
}

int		ft_verification_loop(int ***m, int **solution)
{
	int i;
	int j;
	int undone;

	i = -1;
	undone = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			undone += ft_verification(m, solution, i, j);
		}
	}
	return (undone);
}

void	ft_verification_to_clear(int **view, int ***m, int **sol, int safe)
{
	int undone;

	undone = ft_verification_loop(m, sol);
	if (undone)
	{
		if (safe > 1000000)
			ft_error(0);
		else
		{
			ft_sequence_filtration(view, m);
			ft_verification_to_clear(view, m, sol, safe + 1);
		}
	}
}
