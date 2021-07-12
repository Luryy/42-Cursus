/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/30 08:09:15 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/12 18:40:22 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *format, ...)
{
	va_list	params;
	char	*str;

	str = ft_strdup((char *)format);
	if (!str)
		return (0);
	va_start(params, format);
	va_end(params);
	free(str);
	return (1);
}
