/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 22:29:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/25 16:23:36 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_parse_pipe(int i, t_exec *exec_info, int fd_in)
{
	int	fd[2];
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (fd_in > 0)
		{
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		close(fd[0]);
		ft_execute_cmd(&(exec_info[i]), 0);
	}
	else
	{
		close(fd[1]);
		ft_pipe(exec_info, i + 1, fd[0]);
	}
	waitpid(pid, NULL, 0);
	return (pid);
}

static int	ft_parse_last(int i, t_exec *exec_info, int fd_in)
{
	int	pid;

	pid = fork();
	if (pid == 0)
	{
		if (fd_in > 0)
		{
			dup2(fd_in, STDIN_FILENO);
			close(fd_in);
		}
		ft_execute_cmd(&(exec_info[i]), 0);
	}
	else if (fd_in > 0)
		close(fd_in);
	waitpid(pid, NULL, 0);
	return (pid);
}

void	ft_pipe(t_exec *exec_info, int i, int fd_in)
{
	if (exec_info[i].next_type == PIPE)
		ft_parse_pipe(i, exec_info, fd_in);
	else if (exec_info[i].next_type == LAST)
		ft_parse_last(i, exec_info, fd_in);
	else
		ft_redirects(exec_info, i, fd_in);
}
