/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permutation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 14:59:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 20:41:15 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	save(int *v, int size, int *line, int **permut)
{
	int i;

	i = -1;
	if (v != 0)
	{
		while (++i < size)
		{
			permut[*line][i] = v[i];
		}
		*line = *line + 1;
	}
}

void	swap(int *v, const int i, const int j)
{
	int t;

	t = v[i];
	v[i] = v[j];
	v[j] = t;
}

void	rotate_left(int *v, const int start, const int n)
{
	int tmp;
	int i;

	tmp = v[start];
	i = start - 1;
	while (++i < n - 1)
	{
		v[i] = v[i + 1];
	}
	v[n - 1] = tmp;
}

void	permute(int *v, const int start, int *line, int **permut)
{
	int i;
	int j;

	save(v, 4, line, permut);
	if (start < 4)
	{
		i = 4 - 1;
		while (--i >= start)
		{
			j = i;
			while (++j < 4)
			{
				swap(v, i, j);
				permute(v, i + 1, line, permut);
			}
			rotate_left(v, i, 4);
		}
	}
}

int		*init(int n)
{
	int i;
	int *v;

	v = malloc(sizeof(int) * 4);
	i = -1;
	while (++i < n)
		v[i] = i + 1;
	return (v);
}
