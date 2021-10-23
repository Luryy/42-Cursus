/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:58:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 12:42:38 by lyuri-go         ###   ########.fr       */
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

static void	ft_parse_nbrs(char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;
	t_list	*last_item;

	i = 0;
	while (argv[++i])
	{
		info = malloc(sizeof(t_info));
		info->value = ft_atoi(argv[i]);
		ft_validate(argv[i], content, info);
		if (i == 1)
			info->next_ordered = NULL;
		else
			info->next_ordered = last_item;
		i_list = ft_lstnew(info);
		if (i == 1)
			content->list_a = i_list;
		else
			ft_lstadd_back(&last_item, i_list);
		last_item = i_list;
	}
}

static void	ft_parse_str(char **argv, t_content *content)
{
	int		i;
	t_info	*info;
	t_list	*i_list;
	t_list	*last_item;

	i = -1;
	while (argv[++i])
	{
		info = malloc(sizeof(t_info));
		info->value = ft_atoi(argv[i]);
		ft_validate(argv[i], content, info);
		if (i == 0)
			info->next_ordered = NULL;
		else
			info->next_ordered = last_item;
		i_list = ft_lstnew(info);
		if (i == 0)
			content->list_a = i_list;
		else
			ft_lstadd_back(&last_item, i_list);
		last_item = i_list;
	}
}

void	ft_init_args(int argc, char **argv, t_content *content)
{
	if (argc == 2 && argv[1][0] > 9)
	{
		argv = ft_split(argv[1], ' ');
		ft_parse_str(argv, content);
	}
	else
		ft_parse_nbrs(argv, content);
	return ;
}
