/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_populate_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:45:07 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/10 17:27:36 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_populate_matrix(int **m, int *values, int lines, int coloumns)
{
	int i;
	int j;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < coloumns)
			m[i][j] = values[(i * coloumns) + j];
	}
}
