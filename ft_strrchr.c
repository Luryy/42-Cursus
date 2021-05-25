/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:30:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/25 18:42:10 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *last;

	last = NULL;
	while(*s)
	{
		if(*s == c)
			last = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (last);
};
