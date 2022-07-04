/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 16:01:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/15 01:12:24 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int *p;
	int i;

	i = -1;
	if (min >= max)
		return (0);
	else
	{
		p = malloc(sizeof(int) * (max - min));
		while (++i < max - min)
			p[i] = min + i;
	}
	return (p);
}
