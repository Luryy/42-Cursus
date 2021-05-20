/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:46:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/20 20:16:09 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*dest_char;
	const char	*src_char;
	int			i;

	dest_char = dest;
	src_char = src;
	i = -1;
	if (dest > src)
		while(++i < (int)n)
			dest_char[i] = src_char[i];
	else
		while(--n + 1)
			dest_char[n] = src_char[n];

	return (dest);
};
