/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 01:30:15 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/06 01:55:07 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int count;
	int swap;
	int repetitions;

	count = -1;
	repetitions = size / 2;
	size--;
	while (++count < repetitions)
	{
		swap = tab[count];
		tab[count] = tab[size - count];
		tab[size - count] = swap;
	}
}
