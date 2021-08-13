/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 08:40:08 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/14 08:48:26 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

static int	ft_output(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.dot >= 0)
		count += ft_print_width(flags.dot - 1, ft_strlen(str) - 1, 1);
	count += ft_putsp(str, ft_strlen(str));
	return (count);
}

static int	ft_put_u(char *str, t_flags flags)
{
	int	count;

	count = 0;
	if (flags.minus == 1)
		count += ft_output(str, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += ft_print_width(flags.width, 0, 0);
	}
	else
		count += ft_print_width(flags.width, ft_strlen(str), flags.zero);
	if (flags.minus == 0)
		count += ft_output(str, flags);
	return (count);
}

int	ft_print_u(unsigned int num, t_flags flags)
{
	int		count;
	char	*str;

	count = 0;
	num = (unsigned int)(4294967295 + 1 + num);
	if (flags.dot == 0 && num == 0)
	{
		count += ft_print_width(flags.width, 0, 0);
		return (count);
	}
	str = ft_u_itoa(num);
	count = ft_put_u(str, flags);
	free(str);
	return (count);
}
