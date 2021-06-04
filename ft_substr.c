/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 15:36:21 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/04 18:20:13 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	int				total_verify;

	total_verify = ft_strlen((char *)s + start);
	if (len > (size_t)total_verify)
		len = (size_t)total_verify;
	sub = malloc((len + 1) * sizeof(char));
	if (!sub || s == NULL)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && (size_t)i < len)
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
