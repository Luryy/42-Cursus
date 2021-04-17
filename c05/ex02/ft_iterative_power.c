/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 17:55:22 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 18:15:58 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int pow;

	pow = 1;
	if (!(power >= 0))
		return (0);
	while (power > 0)
	{
		pow *= nb;
		power--;
	}
	return (pow);
}
