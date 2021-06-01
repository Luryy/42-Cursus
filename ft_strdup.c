/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 19:44:29 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/01 18:26:53 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*p;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	p = (char *)malloc(src_len + 1);
	i = -1;
	while (++i < src_len)
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}
