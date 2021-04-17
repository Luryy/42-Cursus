/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 02:39:37 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/08 01:07:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_print_comb2(void)
{
	int first;
	int second;

	first = -1;
	while (++first <= 98)
	{
		second = first;
		while (++second <= 99)
		{
			if (first < second)
			{
				ft_putchar((first / 10) + '0');
				ft_putchar((first % 10) + '0');
				ft_putchar(' ');
				ft_putchar((second / 10) + '0');
				ft_putchar((second % 10) + '0');
				if (!(first == 98 && second == 99))
				{
					ft_putchar(',');
					ft_putchar(' ');
				}
			}
		}
	}
}
