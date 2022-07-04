/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:53:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 22:40:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
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

char				*ft_strdup(char *src)
{
	char	*p;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	p = malloc(src_len + 1);
	if (!p)
		return (0);
	i = -1;
	while (++i < src_len)
		p[i] = src[i];
	p[i] = '\0';
	return (p);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*struct_matrix;
	int			i;

	struct_matrix = malloc(((ac + 1) * sizeof(t_stock_str)));
	if (!struct_matrix)
		return (0);
	i = -1;
	while (++i < ac)
	{
		if (av[i])
		{
			struct_matrix[i].size = ft_strlen(av[i]);
			struct_matrix[i].str = ft_strdup(av[i]);
			struct_matrix[i].copy = ft_strdup(av[i]);
		}
		else
		{
			struct_matrix[i].size = 0;
			struct_matrix[i].str = 0;
			struct_matrix[i].copy = 0;
		}
	}
	struct_matrix[i].str = 0;
	return (struct_matrix);
}
