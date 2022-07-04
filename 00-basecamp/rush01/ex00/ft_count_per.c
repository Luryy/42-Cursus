/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_per.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 19:24:36 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 20:46:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_view_per_st_col(int *permutantion, int total, int ***mp, int j)
{
	int i;
	int k;
	int max_value;
	int views;
	int perm_includ;

	i = -1;
	max_value = 0;
	perm_includ = 0;
	views = 0;
	while (++i < 4)
	{
		k = -1;
		while (++k < 4)
			if (permutantion[i] == mp[i][j][k])
				perm_includ += 1;
		if (permutantion[i] > max_value)
		{
			views++;
			max_value = permutantion[i];
		}
	}
	if (views == total && perm_includ == 4)
		return (1);
	return (0);
}

int		ft_count_view_per_ed_col(int *permutantion, int total, int ***mp, int j)
{
	int i;
	int k;
	int max_value;
	int views;
	int perm_includ;

	i = 4;
	max_value = 0;
	perm_includ = 0;
	views = 0;
	while (--i > -1)
	{
		k = -1;
		while (++k < 4)
			if (permutantion[i] == mp[i][j][k])
				perm_includ += 1;
		if (permutantion[i] > max_value)
		{
			views++;
			max_value = permutantion[i];
		}
	}
	if (views == total && perm_includ == 4)
		return (1);
	return (0);
}

int		ft_count_view_per_st_ln(int *permutantion, int total, int ***mp, int i)
{
	int j;
	int k;
	int max_value;
	int views;
	int perm_includ;

	j = -1;
	max_value = 0;
	perm_includ = 0;
	views = 0;
	while (++j < 4)
	{
		k = -1;
		while (++k < 4)
			if (permutantion[j] == mp[i][j][k])
				perm_includ += 1;
		if (permutantion[j] > max_value)
		{
			views++;
			max_value = permutantion[j];
		}
	}
	if (views == total && perm_includ == 4)
		return (1);
	return (0);
}

int		ft_count_view_per_ed_ln(int *permutantion, int total, int ***mp, int i)
{
	int j;
	int k;
	int max_value;
	int views;
	int perm_includ;

	j = 4;
	max_value = 0;
	perm_includ = 0;
	views = 0;
	while (--j > -1)
	{
		k = -1;
		while (++k < 4)
			if (permutantion[j] == mp[i][j][k])
				perm_includ += 1;
		if (permutantion[j] > max_value)
		{
			views++;
			max_value = permutantion[j];
		}
	}
	if (views == total && perm_includ == 4)
		return (1);
	return (0);
}

int		ft_count_view_per_start(int *permutantion, int total)
{
	int i;
	int max_value;
	int views;

	i = -1;
	max_value = 0;
	views = 0;
	while (++i < 4)
	{
		if (permutantion[i] > max_value)
		{
			views++;
			max_value = permutantion[i];
		}
	}
	if (views == total)
		return (1);
	else
		return (0);
}
