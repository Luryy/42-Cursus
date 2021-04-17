/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solution_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 22:55:11 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:06:06 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_solution_matrix(int i, int j, int new_value, int **solution)
{
	if (solution[i][j] != new_value && solution[i][j] != 0)
	{
		ft_error(0);
	}
	else
		solution[i][j] = new_value;
}
