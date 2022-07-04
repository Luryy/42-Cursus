/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence_filtration.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 03:49:35 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:06:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_seqf_coloumn_view_start(int j, int view, int ***mp, int **permut)
{
	int	i;
	int	k;
	int	p;
	int is_solve;

	i = -1;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
		{
			if (mp[i][j][k] != 0)
			{
				p = -1;
				is_solve = 0;
				while (++p < 24)
					if (permut[p][i] == mp[i][j][k])
						is_solve +=
							ft_count_view_per_st_col(permut[p], view, mp, j);
				if (is_solve == 0)
					ft_clear_value(i, j, mp[i][j][k], mp);
			}
		}
	}
}

void	ft_seqf_coloumn_view_end(int j, int view, int ***mp, int **permut)
{
	int	i;
	int	k;
	int	p;
	int is_solve;

	i = 4;
	while (--i > -1)
	{
		k = -1;
		while (++k < 4)
		{
			if (mp[i][j][k] != 0)
			{
				p = -1;
				is_solve = 0;
				while (++p < 24)
					if (permut[p][i] == mp[i][j][k])
						is_solve +=
							ft_count_view_per_ed_col(permut[p], view, mp, j);
				if (is_solve == 0)
					ft_clear_value(i, j, mp[i][j][k], mp);
			}
		}
	}
}

void	ft_seqf_line_view_start(int i, int view, int ***mp, int **permut)
{
	int	j;
	int	k;
	int	p;
	int is_solve;

	j = -1;
	while (++j < 4)
	{
		k = -1;
		while (++k < 4)
		{
			if (mp[i][j][k] != 0)
			{
				p = -1;
				is_solve = 0;
				while (++p < 24)
					if (permut[p][j] == mp[i][j][k])
						is_solve +=
							ft_count_view_per_st_ln(permut[p], view, mp, i);
				if (is_solve == 0)
					ft_clear_value(i, j, mp[i][j][k], mp);
			}
		}
	}
}

void	ft_seqf_line_view_end(int i, int view, int ***mp, int **permut)
{
	int	j;
	int	k;
	int	p;
	int is_solve;

	j = 4;
	while (--j > -1)
	{
		k = -1;
		while (++k < 4)
		{
			if (mp[i][j][k] != 0)
			{
				p = -1;
				is_solve = 0;
				while (++p < 24)
					if (permut[p][j] == mp[i][j][k])
						is_solve +=
							ft_count_view_per_ed_ln(permut[p], view, mp, i);
				if (is_solve == 0)
					ft_clear_value(i, j, mp[i][j][k], mp);
			}
		}
	}
}

void	ft_sequence_filtration(int **views, int ***mp)
{
	int d;
	int *v;
	int **permut;
	int line;

	permut = ft_matrix_factory(24, 4);
	v = init(4);
	line = 0;
	permute(v, 0, &line, permut);
	d = -1;
	while (++d < 8)
	{
		if (d < 4)
		{
			ft_seqf_coloumn_view_start(d, views[d][0], mp, permut);
			ft_seqf_coloumn_view_end(d, views[d][1], mp, permut);
		}
		else
		{
			ft_seqf_line_view_start(d - 4, views[d][0], mp, permut);
			ft_seqf_line_view_end(d - 4, views[d][1], mp, permut);
		}
	}
}
