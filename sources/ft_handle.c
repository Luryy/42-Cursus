/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:00:06 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/14 09:00:31 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_handle(int c, t_flags flags, va_list args)
{
	int	count;

	count = 0;
	if (c == 'c')
		count = ft_print_c(va_arg(args, int), flags);
	else if (c == 's')
		count = ft_print_s(va_arg(args, char *), flags);
	else if (c == 'p')
		count = ft_print_p(va_arg(args, size_t), flags);
	else if (c == 'd' || c == 'i')
		count = ft_print_int(va_arg(args, int), flags);
	else if (c == 'u')
		count += ft_print_u(va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count += ft_print_x(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count += ft_print_x(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count += ft_print_percent(flags);
	return (count);
}
