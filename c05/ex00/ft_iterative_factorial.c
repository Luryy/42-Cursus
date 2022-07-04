/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 15:23:16 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 16:54:52 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int fac;

	fac = 1;
	if (!(nb >= 0))
		return (0);
	while (nb != 0)
	{
		fac *= nb;
		nb--;
	}
	return (fac);
}
