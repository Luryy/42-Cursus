/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 21:31:20 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/15 12:57:50 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		is_last_number(int *number_array, int total_index)
{
	int	loop;
	int	current_max;
	int	max_array[10];

	loop = total_index - 1;
	current_max = 9;
	while (loop >= 0)
	{
		max_array[loop] = current_max;
		loop = loop - 1;
		current_max = current_max - 1;
	}
	loop = 0;
	while (loop < total_index)
	{
		if (!(number_array[loop] == max_array[loop]))
		{
			return (0);
		}
		loop = loop + 1;
	}
	return (1);
}

void	print_numbers(int *number_array, int total_index)
{
	int loop;
	int number_to_print;

	loop = 0;
	while (loop < total_index)
	{
		number_to_print = number_array[loop] + 48;
		write(1, &number_to_print, 1);
		if (loop == total_index - 1 &&
		!is_last_number(number_array, total_index))
		{
			write(1, ", ", 2);
		}
		loop = loop + 1;
	}
}

void	print_num(int *number_array, int current_index, int total_index)
{
	number_array[current_index] = number_array[current_index] - 1;
	while (++number_array[current_index] < 10)
	{
		if (current_index == 0 ||
		number_array[current_index - 1] < number_array[current_index])
		{
			print_num(number_array, current_index + 1, total_index);
			if (current_index == total_index - 1)
			{
				print_numbers(number_array, total_index);
			}
		}
		number_array[current_index + 1] = 0;
	}
}

void	ft_print_combn(int n)
{
	int	loop;
	int	n_array[10];

	loop = 0;
	if (0 >= n || n >= 10)
		return ;
	while (loop < n)
	{
		n_array[loop] = loop;
		loop = loop + 1;
	}
	print_num(n_array, 0, n);
}
