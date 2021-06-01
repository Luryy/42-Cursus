/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 18:19:52 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:42:46 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*dest_char;
	const char	*src_char;
	size_t		i;

	dest_char = dest;
	src_char = src;
	i = 0;
	while (i < n)
	{
		dest_char[i] = src_char[i];
		if (src_char[i] == c)
			return (&dest_char[i + 1]);
		i++;
	}
	return (NULL);
}
