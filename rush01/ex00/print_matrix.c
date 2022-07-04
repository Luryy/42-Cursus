/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_matrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:17:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 22:08:09 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int **m, int lines, int coloumns)
{
	int i;
	int j;
	int to_print;

	i = -1;
	while (++i < lines)
	{
		j = -1;
		while (++j < coloumns)
		{
			to_print = m[i][j] + '0';
			write(1, &to_print, 1);
			if (j != coloumns - 1)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
	}
}
