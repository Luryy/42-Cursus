/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:40:08 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/14 08:47:17 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_output(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += ft_print_width(flags.dot, ft_strlen(str), 0);
		count += ft_putsp(str, flags.dot);
	}
	else
		count += ft_putsp(str, ft_strlen(str));
	return (count);
}

int	ft_print_s(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (!str)
		str = ("(null)");
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += ft_output(str, flags);
	if (flags.dot >= 0)
		count += ft_print_width(flags.width, flags.dot, 0);
	else
		count += ft_print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_output(str, flags);
	return (count);
}
