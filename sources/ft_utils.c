/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:23:31 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 11:21:23 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int nb_1, int nb_2)
{
	if (nb_1 > nb_2)
		return (nb_1);
	return (nb_2);
}

int	ft_min(int nb_1, int nb_2)
{
	if (nb_1 < nb_2)
		return (nb_1);
	return (nb_2);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}
