/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_views.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 01:42:17 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 20:45:48 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_coloumn_view_start(int j, int **solution)
{
	int i;
	int max_value;
	int views;

	i = -1;
	max_value = 0;
	views = 0;
	while (++i < 4)
	{
		if (solution[i][j] > max_value)
		{
			views++;
			max_value = solution[i][j];
		}
	}
	return (views);
}

int	ft_count_coloumn_view_end(int j, int **solution)
{
	int i;
	int max_value;
	int views;

	i = 4;
	max_value = 0;
	views = 0;
	while (--i > -1)
	{
		if (solution[i][j] > max_value)
		{
			views++;
			max_value = solution[i][j];
		}
	}
	return (views);
}

int	ft_count_line_view_start(int i, int **solution)
{
	int j;
	int max_value;
	int views;

	j = -1;
	max_value = 0;
	views = 0;
	while (++j < 4)
	{
		if (solution[i][j] > max_value)
		{
			views++;
			max_value = solution[i][j];
		}
	}
	return (views);
}

int	ft_count_line_view_end(int i, int **solution)
{
	int j;
	int max_value;
	int views;

	j = 4;
	max_value = 0;
	views = 0;
	while (--j > -1)
	{
		if (solution[i][j] > max_value)
		{
			views++;
			max_value = solution[i][j];
		}
	}
	return (views);
}
