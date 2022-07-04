/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possibilities_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 14:40:56 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:06:35 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_clear_value(int i, int j, int clear_value, int ***m)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		if (m[i][j][k] == clear_value)
		{
			m[i][j][k] = 0;
		}
	}
}

void	ft_clear_line(int i, int current_coloumn, int solution_value, int ***m)
{
	int j;
	int k;

	j = -1;
	while (++j < 4)
	{
		k = -1;
		while (++k < 4)
		{
			if (m[i][j][k] == solution_value && j != current_coloumn)
				m[i][j][k] = 0;
		}
	}
}

void	ft_clear_coloumn(int j, int current_line, int solution_value, int ***m)
{
	int i;
	int k;

	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
		{
			if (m[i][j][k] == solution_value && i != current_line)
				m[i][j][k] = 0;
		}
	}
}

void	ft_clear_solution(int i, int j, int solution_value, int ***m)
{
	int k;

	k = -1;
	while (++k < 4)
	{
		if (m[i][j][k] != solution_value)
		{
			m[i][j][k] = 0;
			ft_clear_line(i, j, solution_value, m);
			ft_clear_coloumn(j, i, solution_value, m);
		}
	}
}

int		***ft_possibilities_matrix(void)
{
	int i;
	int j;
	int k;
	int ***m;

	m = malloc(4 * sizeof(int **));
	i = -1;
	while (++i < 4)
	{
		m[i] = malloc(4 * sizeof(int *));
		j = -1;
		while (++j < 4)
		{
			m[i][j] = malloc(4 * sizeof(int *));
			k = -1;
			while (++k < 4)
			{
				m[i][j][k] = k + 1;
			}
		}
	}
	return (m);
}
