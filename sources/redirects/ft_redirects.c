/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:13:05 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/20 19:59:53 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_redirects(t_exec *exec_info, int i, int fdi, int fdo)
{
	printf("main %d\n", i);
	(void)fdo;
	if (exec_info[i].next_type == PIPE)
		ft_pipe(exec_info, i, fdi);
	if (exec_info[i].next_type == REDIRECT_TO_SINGLE
		|| exec_info[i].next_type == REDIRECT_TO_DOUBLE)
		ft_redirect_to(exec_info, i, fdi);
	if (exec_info[i].next_type == REDIRECT_FROM_SINGLE)
		ft_redirect_from_single(exec_info);
	if (exec_info[i].next_type == REDIRECT_FROM_DOUBLE)
		ft_redirect_from_double(exec_info, i);
}
