/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:41:27 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/14 13:25:06 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	unsigned	int	pow;
	unsigned	int	count;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	count = 0;
	pow = 0;
	while (pow < (unsigned int)nb && count < 46341)
	{
		pow = count * count;
		if (pow == (unsigned int)nb)
			return (count);
		count++;
	}
	return (0);
}
