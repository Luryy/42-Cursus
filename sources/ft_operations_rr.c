/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:35:01 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 16:54:38 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_rra(t_content *content)
{
	ft_shift_down(&(content->list_a));
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_content *content)
{
	ft_shift_down(&(content->list_b));
	ft_putstr_fd("rrb\n", 1);
}

void	ft_rrr(t_content *content)
{
	ft_shift_down(&(content->list_b));
	ft_shift_down(&(content->list_a));
	ft_putstr_fd("rrr\n", 1);
}
