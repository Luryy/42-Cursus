/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:21:44 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/23 13:15:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_clean(t_content *content)
{
	if (content->list_a)
		ft_lstclear(&(content->list_a), free);
	if (content->list_b)
		ft_lstclear(&(content->list_b), free);
}

void	ft_error(t_content *content)
{
	ft_putstr_fd("Error\n", 2);
	ft_clean(content);
	exit(EXIT_FAILURE);
}

void	ft_validation_error(t_content *content, t_info *inf, char **argv, int i)
{
	free(inf);
	if (content->is_string_params)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	ft_error(content);
}
