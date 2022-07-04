/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:41:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 19:57:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

void	ft_putnbr(int nb)
{
	unsigned int nbr;
	unsigned int print_nbr;

	if (nb < 0)
	{
		ft_putstr("-");
		nbr = nb * -1;
	}
	else
		nbr = nb;
	if (nbr >= 0 && nbr <= 9)
	{
		print_nbr = nbr + '0';
		write(1, &print_nbr, 1);
	}
	else if (nbr > 9)
	{
		ft_putnbr(nbr / 10);
		ft_putnbr(nbr % 10);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	while ((*par).str)
	{
		ft_putstr((*par).str);
		ft_putstr("\n");
		ft_putnbr((*par).size);
		ft_putstr("\n");
		ft_putstr((*par).copy);
		ft_putstr("\n");
		par++;
	}
}
