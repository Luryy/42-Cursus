/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_vector.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 02:04:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/11 20:24:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_set_init_ref(void)
{
	int *ref;

	ref = malloc(16 * sizeof(int));
	ref[0] = 0;
	ref[1] = 2;
	ref[2] = 4;
	ref[3] = 6;
	ref[4] = 1;
	ref[5] = 3;
	ref[6] = 5;
	ref[7] = 7;
	ref[8] = 8;
	ref[9] = 10;
	ref[10] = 12;
	ref[11] = 14;
	ref[12] = 9;
	ref[13] = 11;
	ref[14] = 13;
	ref[15] = 15;
	return (ref);
}

int	*ft_view_vector(char *v)
{
	int *view;
	int *ref;
	int i;
	int count;

	view = malloc(16 * sizeof(int));
	ref = ft_set_init_ref();
	i = 0;
	count = 0;
	while (i < 31)
	{
		view[ref[count]] = v[i] - 48;
		i += 2;
		count++;
	}
	return (view);
}
