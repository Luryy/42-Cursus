/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_factory.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:29:16 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 20:43:13 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_matrix_factory(int lines, int coloumns)
{
	int **matrix;
	int i;
	int j;

	matrix = malloc(lines * sizeof(int *));
	i = -1;
	while (++i < lines)
	{
		matrix[i] = malloc(coloumns * sizeof(int));
		j = -1;
		while (++j < coloumns)
		{
			matrix[i][j] = 0;
		}
	}
	return (matrix);
}
