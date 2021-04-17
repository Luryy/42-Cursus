/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:06:35 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 18:16:07 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (!(power >= 0))
		return (0);
	if (power == 0)
		return (1);
	nb *= ft_recursive_power(nb, power - 1);
	return (nb);
}
