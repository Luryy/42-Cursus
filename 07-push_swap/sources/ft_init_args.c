/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 08:58:30 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 09:05:05 by lyuri-go         ###   ########.fr       */
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

static void	ft_validate(char **argv, t_content *content, t_info *info, int i)
{
	int	j;

	j = -1;
	while (argv[i][++j])
	{
		if (argv[i][j] != '+' && argv[i][j] != '-'
			&& argv[i][j] != ' ' && !ft_isdigit(argv[i][j]))
			ft_validation_error(content, info, argv, i);
	}
	if (ft_validate_duplicated(content->list_a, info->value))
		ft_validation_error(content, info, argv, i);
	if (content->is_string_params)
		free(argv[i]);
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
		info->value = ft_atoi_safe(content, argv, info, i);
		ft_validate(argv, content, info, i);
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
		info->value = ft_atoi_safe(content, argv, info, i);
		ft_validate(argv, content, info, i);
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
		if (!*argv)
		{
			free(argv);
			ft_error(content);
		}
		content->is_string_params = 1;
		ft_parse_str(argv, content);
		free(argv);
	}
	else
	{
		content->is_string_params = 0;
		ft_parse_nbrs(argv, content);
	}
	return ;
}
