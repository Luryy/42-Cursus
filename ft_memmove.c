/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:46:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:44:13 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;
	size_t				i;

	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	if (dest > src)
		while (++i <= n)
			dest_char[n - i] = src_char[n - i];
	else
		while (--n + 1)
			*(dest_char++) = *(src_char++);
	return (dest);
}
