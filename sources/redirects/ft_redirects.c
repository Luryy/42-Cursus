/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:13:05 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/19 00:04:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_redirects(t_exec *exec_info)
{
	if (exec_info->next_type == PIPE)
		ft_pipe(exec_info, 0, -1);
	if (exec_info->next_type == REDIRECT_TO_SINGLE
		|| exec_info->next_type == REDIRECT_TO_DOUBLE)
		ft_redirect_to(exec_info, 0);
	if (exec_info->next_type == REDIRECT_FROM_SINGLE)
		ft_redirect_from_single(exec_info);
	if (exec_info->next_type == REDIRECT_FROM_DOUBLE)
		ft_redirect_from_double(exec_info, 0);
}
