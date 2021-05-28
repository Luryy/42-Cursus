/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 11:18:21 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/28 11:26:42 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		s_len;
	int		i;

	s_len = ft_strlen((char *)s);
	str = malloc(sizeof(char) * (s_len + 1));
	if (!str || s == NULL)
		return (NULL);
	i = -1;
	while(s[++i] != '\0')
	{
		str[i] = f(i, s[i]);
	}
	return (str);
};
