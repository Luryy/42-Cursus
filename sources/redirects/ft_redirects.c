/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:13:05 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/06 18:19:53 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h> 

void	ft_redirects(t_exec *exec_info)
{
	if (exec_info->next_type == PIPE)
		ft_pipe(exec_info, 0, -1);
}