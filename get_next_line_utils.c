/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:31:32 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/16 22:02:46 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

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
	p = (char *)malloc(src_len + 1);
	if (!p)
		return (NULL);
	i = -1;
	while (++i < src_len)
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}

char	*ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (NULL);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_char;
	const unsigned char	*src_char;
	size_t				i;

	if ((dest == NULL && src == NULL) || n == 0)
		return (dest);
	dest_char = (unsigned char *)dest;
	src_char = (unsigned char *)src;
	i = 0;
	if (dest > src)
		while (++i <= n)
			dest_char[n - i] = src_char[n - i];
	else
		while (--n + 1)
			*(dest_char++) = *(src_char++);
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*sub;
	int				total_verify;

	if (start > (unsigned int)ft_strlen((char *)s))
	{
		sub = (char *) malloc(sizeof(char) * len + 1);
		if (!sub)
			return (NULL);
		return (sub);
	}
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
