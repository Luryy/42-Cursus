/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_calc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:18:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 16:02:41 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_distance_to_tag(int tag, int size)
{
	if (tag >= size / 2)
		tag -= size;
	return (tag);
}

t_list	*ft_get_closest_group(t_list *list, int actual_group, int group_total)
{
	t_list	*closest;
	t_list	*cur;
	int		distance;
	int		cur_dist;

	distance = MAX_INT;
	closest = NULL;
	cur = list;
	while (cur)
	{
		if (cur->content->index <= group_total * actual_group
			&& !cur->content->tag_keep)
		{
			cur_dist = ft_distance_to_index(list, cur->content->index);
			if (ft_abs(cur_dist) < ft_abs(distance))
			{
				distance = cur_dist;
				closest = cur;
				if (distance == 0)
					break ;
			}
		}
		cur = cur->next;
	}
	return (closest);
}

static int	ft_get_distance(t_list *list, int t, int size)
{
	t_list	*p;
	t_list	*c;
	int		c_max[3];

	c_max[2] = 0;
	p = ft_lstlast(list);
	c = list;
	c_max[1] = MAX_INT;
	while (c)
	{
		if ((p->content->index > c->content->index
				&& (t < c->content->index || t > p->content->index))
			|| (t > p->content->index && t < c->content->index))
		{
			c_max[0] = c_max[2];
			if (c_max[0] > size / 2)
				c_max[0] -= size;
			if (ft_abs(c_max[0]) < c_max[1])
				c_max[1] = c_max[0];
		}
		p = c;
		c = c->next;
		c_max[2]++;
	}
	return (c_max[1]);
}

void	ft_set_rotation(t_content *cont, int max_dist, int *a_rot, int *b_rot)
{
	int	dist_total;
	int	insert;
	int	distance_b;
	int	i;

	i = 0;
	cont->list_a_ref = cont->list_b;
	while (cont->list_a_ref)
	{
		distance_b = ft_distance_to_tag(i++, cont->total_nb - cont->length);
		insert = ft_get_distance(
				cont->list_a, cont->list_a_ref->content->index, cont->length);
		dist_total = ft_abs(insert) + ft_abs(distance_b);
		if (insert > 0 && distance_b > 0)
			dist_total -= ft_min(distance_b, insert);
		if (insert < 0 && distance_b < 0)
			dist_total += ft_max(distance_b, insert);
		if (dist_total < max_dist)
		{
			max_dist = dist_total;
			*a_rot = insert;
			*b_rot = distance_b;
		}
		cont->list_a_ref = cont->list_a_ref->next;
	}
}

int	ft_distance_to_index(t_list *list, int index)
{
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(list);
	while (list)
	{
		if (list->content->index == index)
			break ;
		list = list->next;
		i++;
	}
	if (i > size / 2)
		i -= size;
	return (i);
}
