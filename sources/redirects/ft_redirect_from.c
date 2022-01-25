/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:05:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/25 22:25:51 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_is_only_single(t_exec *exec_info, int i)
{
	int	count;

	count = i;
	if (i > 1 && (exec_info[i - 2].next_type == REDIRECT_TO_SINGLE
			|| exec_info[i - 2].next_type == REDIRECT_TO_DOUBLE))
		count = i - 1;
	while (exec_info[count++].next_type == REDIRECT_FROM_SINGLE)
		if (exec_info[count].next_type != REDIRECT_FROM_SINGLE
			&& exec_info[count].next_type != REDIRECT_FROM_DOUBLE)
			return (1);
	return (0);
}

void	ft_redirect_from(t_exec *exec_info, int i)
{
	if (ft_is_only_single(exec_info, i))
		ft_redirect_from_single(exec_info, i);
	else
		ft_redirect_from_double(exec_info, i);
}
