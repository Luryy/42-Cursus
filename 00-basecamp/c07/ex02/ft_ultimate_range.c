/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:53:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 01:19:20 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int *p;
	int len;
	int i;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	len = max - min;
	*range = malloc(len * 4);
	if (*range == NULL)
	{
		*range = 0;
		return (-1);
	}
	p = *range;
	i = 0;
	while (i < len)
	{
		p[i] = min + i;
        i++;
	}
	return (len);
}
