/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_possibilities_matrix.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:17:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:07:50 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_possibilities_matrix(int ***m)
{
	int i;
	int j;
	int k;
	int to_print;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			k = -1;
			while (++k < 4)
			{
				to_print = m[i][j][k] + '0';
				write(1, &to_print, 1);
			}
			write(1, ",", 1);
		}
		write(1, "\n", 1);
	}
}
