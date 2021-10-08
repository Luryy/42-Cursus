/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:40:08 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/14 09:09:39 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_print_c(char c, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		ft_putchar_fd(c, 1);
	count = ft_print_width(flags.width, 1, 0);
	if (flags.minus == 0)
		ft_putchar_fd(c, 1);
	count++;
	return (count);
}
