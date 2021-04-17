/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:54:07 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/14 12:04:41 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int count;

	if (nb == 2 || nb == 3)
		return (1);
	else if (nb < 2 || nb % 2 == 0 || nb % 3 == 0)
		return (0);
	count = 5;
	while (count * count <= nb)
	{
		if (nb % count == 0 || nb % (count + 2) == 0)
			return (0);
		count += 6;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb > 2147483629)
		return (2147483647);
	while (!ft_is_prime(nb) && nb < 2147483647)
		nb++;
	return (nb);
}
