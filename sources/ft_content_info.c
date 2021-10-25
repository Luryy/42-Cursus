/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:18:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 10:23:43 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_set_content_info(t_content *content)
{
	int	list_size;

	list_size = ft_lstsize(content->list_a);
	content->length = list_size;
	content->total_nb = list_size;
	content->groups = ft_max(1, list_size / 150);
	content->groups_len = list_size / content->groups;
	content->biggest_sequence = ft_biggest_seq_tag(content->list_a, 1);
}

int	ft_is_sequence(t_list *list_a)
{
	int		prev;
	t_list	*next_a;

	if (!list_a)
		return (1);
	next_a = list_a;
	prev = next_a->content->value;
	while (next_a)
	{
		if (prev > next_a->content->value)
			return (0);
		prev = next_a->content->value;
		next_a = next_a->next;
	}
	return (1);
}
