/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:51:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 01:08:24 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int n;

	n = 0;
	while (*str != '\0')
	{
		n++;
		str++;
	}
	return (n);
}

char	*ft_strcat(char *dest, char *src)
{
	char *dest_ini;

	dest_ini = dest;
	while (*dest != '\0')
		dest++;
	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_ini);
}

int		ft_get_str_len(char **strs, int size)
{
	int i;
	int total_size;

	i = -1;
	total_size = 0;
	while (++i < size)
	{
		total_size += ft_strlen(strs[i]);
	}
	return (total_size);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*chain;
	int		total_size;
	int		i;

	if (size <= 0)
	{
		chain = malloc(1);
		return (chain);
	}
	total_size = ft_get_str_len(strs, size);
	total_size += ft_strlen(sep) * (size - 1);
	chain = malloc(total_size);
	if (!chain)
		return (0);
	*chain = '\0';
	i = -1;
	while (++i < size)
	{
		ft_strcat(chain, strs[i]);
		if (i != size - 1)
			ft_strcat(chain, sep);
	}
	return (chain);
}
