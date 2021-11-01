/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 09:54:55 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 18:37:57 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_should_swap(t_list *list)
{
	t_list	swap_b;
	t_list	swap_a;
	int		without_swap;
	int		with_swap;
	int		should_swap;

	swap_b.next = &swap_a;
	swap_b.content = malloc(sizeof(t_info));
	(swap_b.content)->index = list->next->content->index;
	swap_a.next = list->next->next;
	swap_a.content = malloc(sizeof(t_info));
	(swap_a.content)->index = list->content->index;
	without_swap = ft_biggest_seq_tag(list, 0);
	with_swap = ft_biggest_seq_tag(&swap_b, 0);
	should_swap = with_swap > without_swap;
	free(swap_b.content);
	free(swap_a.content);
	return (should_swap);
}

static void	ft_actions(t_content *content, int top_distance)
{
	if (content->list_a && ft_should_swap(content->list_a))
	{
		ft_sa(content, 1);
		content->biggest_sequence = ft_biggest_seq_tag(content->list_a, 1);
	}
	else if (content->list_a && !content->list_a->content->tag_keep
		&& top_distance == 0)
	{
		ft_pb(content, 1);
		(content->length)--;
	}
	else if (content->groups == 1)
		ft_rr(content, 1);
	else
		ft_rotate(content, ft_min(1, ft_max(-1, top_distance)), 0);
}

static void	ft_improve(t_content *content)
{
	if (content->length == 5 && content->biggest_sequence == 2
		&& ft_should_swap(content->list_a)
		&& content->list_a->content->index == 1)
		ft_rra(content, 1);
}

static void	ft_refill_a_from_b(t_content *content)
{
	int	a_rot;
	int	b_rot;

	while (content->list_b)
	{
		ft_set_rotation(content, MAX_INT, &a_rot, &b_rot);
		ft_rotate(content, a_rot, b_rot);
		ft_pa(content, 1);
		(content->length)++;
	}
	ft_rotate(content, ft_distance_to_index(content->list_a, 0), 0);
}

void	ft_sort(t_content *content)
{
	int	top_distance;
	int	actual_group;

	actual_group = 1;
	ft_improve(content);
	while (content->length >= content->biggest_sequence
		&& actual_group <= (content->groups + 1))
	{
		content->list_a_ref = ft_get_closest_group(
				content->list_a, actual_group, content->groups_len);
		if (content->list_a_ref == NULL && ++actual_group)
			continue ;
		top_distance = ft_distance_to_index(
				content->list_a, content->list_a_ref->content->index);
		ft_actions(content, top_distance);
	}
	ft_refill_a_from_b(content);
}
