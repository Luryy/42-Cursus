/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 18:49:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/18 19:31:52 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		*pointer;
	size_t	total_size;
	size_t	i;

	total_size = nmemb * size;
	pointer = malloc(total_size);
	if (pointer == NULL)
		return (NULL);
	i = -1;
	while (++i < total_size)
		pointer[i] = 0;
	return (pointer);
}
