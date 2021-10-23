/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:18:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 15:45:17 by lyuri-go         ###   ########.fr       */
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
