/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:41:24 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 16:43:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int		i;
	int					r;
	const unsigned char	*char_s1;
	const unsigned char	*char_s2;

	r = 0;
	i = 0;
	char_s1 = s1;
	char_s2 = s2;
	while ((char_s1[i] != '\0' || char_s2[i] != '\0') && (i < (unsigned int)n))
	{
		r = char_s1[i] - char_s2[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (r);
}
