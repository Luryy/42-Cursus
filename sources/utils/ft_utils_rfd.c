/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_rfd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 19:01:08 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/25 19:30:52 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	not_have_line(t_exec *exec_info, char *line)
{
	if (!line)
	{
		printf("warning: wanted %s\n", exec_info->cmd);
		return (1);
	}
	return (0);
}

void	check_pipe_and_last(t_exec *exec_info, int fd, int pid, int fdi_to)
{
	ft_redi_from_doub_last(&(exec_info[i]), fd, pid, -1);
	ft_signals();
	close(fdi_to);
}

void	wait_and_handle_sig()
{
{
	waitpid(pid, NULL, 0);
	ft_signals();
}