/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:58:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 10:11:32 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_validate_duplicated(t_list *list, int value)
{
	t_info	*compare_list;

	while (list)
	{
		compare_list = list->content;
		if (compare_list->value == value)
			return (1);
		list = list->next;
	}
	return (0);
}

static void	ft_validate(char *argv, t_content *content, t_info *info)
{
	int	i;

	i = -1;
	while (argv[++i])
	{
		if (argv[i] != '+' && argv[i] != '-'
			&& argv[i] != ' ' && !ft_isdigit(argv[i]))
		{
			free(info);
			ft_error(content);
		}
	}
	if (ft_validate_duplicated(content->list_a, info->value))
	{
		free(info);
		ft_error(content);
	}
}

void	ft_init_args(int argc, char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;
	t_list	*last_item;

	i = 0;
	while (++i < argc)
	{
		info = malloc(sizeof(t_info));
		info->value = ft_atoi(argv[i]);
		ft_validate(argv[i], content, info);
		i_list = ft_lstnew(info);
		if (i == 1)
			content->list_a = i_list;
		else
			ft_lstadd_back(&last_item, i_list);
		last_item = i_list;
	}
	return ;
}
