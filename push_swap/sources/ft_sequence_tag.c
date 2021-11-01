/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sequence_tag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:30:41 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 15:38:55 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_big_seq_tag(t_list *list, t_list *start, int tag)
{
	t_list	*loop;
	int		max_tag;
	int		count;

	max_tag = -1;
	count = 0;
	loop = start;
	while (loop)
	{
		if (tag)
			loop->content->tag_keep = 0;
		if (loop->content->index > max_tag)
		{
			max_tag = loop->content->index;
			count++;
			if (tag)
				loop->content->tag_keep = 1;
		}
		loop = loop->next;
		if (loop == NULL)
			loop = list;
		if (loop == start)
			break ;
	}
	return (count);
}

int	ft_biggest_seq_tag(t_list *start, int tag)
{
	t_list	*t;
	int		max;
	int		count;
	t_list	*max_keep;

	max = 0;
	t = start;
	while (t)
	{
		count = ft_big_seq_tag(start, t, 0);
		if (count > max)
		{
			max = count;
			max_keep = t;
		}
		t = t->next;
	}
	if (tag)
		ft_big_seq_tag(start, max_keep, 1);
	return (max);
}
