/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 18:46:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/25 19:07:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_inside(const char *principal, const char *inside)
{
	int i;

	i = 0;
	while (inside[i] != '\0')
	{
		if (principal[i] != inside[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!(*little))
		return ((char *)big);
	i = 0;
	while (*big != '\0' && i < len)
	{
		if (*big == little[0])
		{
			if (ft_is_inside(big, little))
				return ((char *)big);
		}
		big++;
		i++;
	}
	return (0);
};
