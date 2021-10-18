/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:44 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/18 20:39:39 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_clean(t_content *content)
{
	ft_putstr_fd("Error\n", 1);
	if (content->list_a)
		ft_lstclear(&(content->list_a), free);
	if (content->list_b)
		ft_lstclear(&(content->list_b), free);
	exit(EXIT_FAILURE);
}
