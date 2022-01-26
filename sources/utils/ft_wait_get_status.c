/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait_get_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 01:11:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/26 10:59:53 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_wait_get_status(int pid, int env)
{
	int	status_code;

	if (env == 1)
	{
		signal(SIGINT, ft_signals_standard_exec);
		signal(SIGQUIT, ft_signals_standard_exec);
		waitpid(pid, &status_code, 0);
		ft_signals();
	}
	else
		waitpid(pid, &status_code, 0);
	if (WIFEXITED(status_code))
		mini_s()->last_exec_code = WEXITSTATUS(status_code);
}
