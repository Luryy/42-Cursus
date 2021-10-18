/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:58:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/18 20:34:44 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_init_args(int argc, char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;

	i = 0;
	while (++i < argc)
	{
		info = malloc(sizeof(t_info));
		info->value = ft_atoi(argv[i]);
		i_list = ft_lstnew(info);
		if (i == 1)
			content->list_a = i_list;
		else
			ft_lstadd_back(&(content->list_a), i_list);
	}
	return ;
}
