/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:40:27 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/14 15:59:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*str++)
		n++;
	return (n);
}

char	*ft_strdup(char *src)
{
	char	*p;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	p = malloc(src_len);
	i = -1;
	while (++i < src_len)
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}
