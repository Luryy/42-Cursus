/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 23:07:34 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/07 23:42:32 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	write_non_printable(char c)
{
	char *hex;
	char hexa[2];
	char back;

	back = '\\';
	hex = "0123456789abcdef";
	hexa[1] = hex[c % 16];
	c = c / 16;
	hexa[0] = hex[c % 16];
	write(1, &back, 1);
	write(1, &hexa[0], 2);
}

void	ft_putstr_non_printable(char *str)
{
	while (*str != 0)
	{
		if ((32 <= *str && *str <= 126))
			write(1, str, 1);
		else
			write_non_printable(*str);
		str++;
	}
}
