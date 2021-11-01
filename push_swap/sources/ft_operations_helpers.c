/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_helpers.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 10:51:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 12:35:06 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_swap(t_list **init_ref)
{
	t_list	*swap;
	t_list	*third;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	third = (*init_ref)->next->next;
	swap = *init_ref;
	*init_ref = (*init_ref)->next;
	(*init_ref)->next = swap;
	swap->next = third;
}

void	ft_push_top(t_list **init_ref_1, t_list **init_ref_2)
{
	t_list	*top;

	if (!*init_ref_1)
		return ;
	top = *init_ref_1;
	*init_ref_1 = top->next;
	if (*init_ref_2)
		top->next = *init_ref_2;
	else
		top->next = NULL;
	*init_ref_2 = top;
}

void	ft_shift_up(t_list **init_ref)
{
	t_list	*top;
	t_list	*last;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	top = *init_ref;
	*init_ref = (*init_ref)->next;
	last = ft_lstlast(*init_ref);
	last->next = top;
	top->next = NULL;
}

void	ft_shift_down(t_list **init_ref)
{
	t_list	*last;
	t_list	*prev;

	if (!*init_ref || !(*init_ref)->next)
		return ;
	last = *init_ref;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	last->next = *init_ref;
	*init_ref = last;
	prev->next = NULL;
}
