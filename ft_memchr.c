/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:06:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/21 11:29:47 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_char;
	int				i;

	s_char = s;
	i = -1;
	while(++i < (int)n)
	{
		if (s_char[i] == c)
			return ((void *)&s_char[i]);
	}

	return (NULL);
};
