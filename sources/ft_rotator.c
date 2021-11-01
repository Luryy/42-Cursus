/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotator.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 11:02:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 18:38:20 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_optimize_rotate(t_content *content, int *a_rot, int *b_rot)
{
	while (*a_rot > 0 && *b_rot > 0)
	{
		ft_rr(content, 1);
		(*a_rot)--;
		(*b_rot)--;
	}
	while (*a_rot < 0 && *b_rot < 0)
	{
		ft_rrr(content, 1);
		(*a_rot)++;
		(*b_rot)++;
	}
}

void	ft_rotate(t_content *content, int a_rot, int b_rot)
{
	ft_optimize_rotate(content, &a_rot, &b_rot);
	while (a_rot > 0)
	{
		ft_ra(content, 1);
		a_rot--;
	}
	while (a_rot < 0)
	{
		ft_rra(content, 1);
		a_rot++;
	}
	while (b_rot > 0)
	{
		ft_rb(content, 1);
		b_rot--;
	}
	while (b_rot < 0)
	{
		ft_rrb(content, 1);
		b_rot++;
	}
}
