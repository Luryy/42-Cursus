/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_s_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:35:01 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 16:54:29 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sa(t_content *content)
{
	ft_swap(&(content->list_a));
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_content *content)
{
	ft_swap(&(content->list_b));
	ft_putstr_fd("sb\n", 1);
}

void	ft_ss(t_content *content)
{
	ft_swap(&(content->list_b));
	ft_swap(&(content->list_a));
	ft_putstr_fd("ss\n", 1);
}

void	ft_pa(t_content *content)
{
	ft_push_top(&(content->list_b), &(content->list_a));
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_content *content)
{
	ft_push_top(&(content->list_a), &(content->list_b));
	ft_putstr_fd("pb\n", 1);
}
