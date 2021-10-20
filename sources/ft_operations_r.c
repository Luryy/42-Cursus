/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_r.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:35:01 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 16:54:51 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_ra(t_content *content)
{
	ft_shift_up(&(content->list_a));
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_content *content)
{
	ft_shift_up(&(content->list_b));
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_content *content)
{
	ft_shift_up(&(content->list_a));
	ft_shift_up(&(content->list_b));
	ft_putstr_fd("rr\n", 1);
}
