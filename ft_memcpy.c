/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 17:57:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/20 18:09:39 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_char;
	const char	*src_char;

	dest_char = dest;
	src_char = src;
	while(--n + 1)
		dest_char[n] = src_char[n];
	return (dest);
};
