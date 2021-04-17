/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:46:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/15 17:16:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		base_len_and_verify(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i] != '\0')
	{
		j = 0;
		while (base[j] != '\0')
		{
			if (base[i] == base[j] && i != j)
				return (0);
			j++;
		}
		if (base[i] == '+' || base[i] == '-')
			return (0);
		i++;
	}
	return (i);
}

void	ft_base_converter(int nbr, char *base, int base_len)
{
	unsigned int un_nbr;

	if (nbr < 0)
	{
		write(1, "-", 1);
		un_nbr = nbr * -1;
	}
	else
		un_nbr = nbr;
	if (un_nbr >= (unsigned)base_len)
		ft_base_converter(un_nbr / base_len, base, base_len);
	write(1, &base[un_nbr % base_len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int base_len;

	base_len = base_len_and_verify(base);
	if (base_len < 2)
		return ;
	ft_base_converter(nbr, base, base_len);
}
