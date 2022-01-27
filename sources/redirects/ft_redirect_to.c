/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:58:26 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 10:02:40 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	verify_last_pipe(t_exec *exec_info, int fd_pipe[2])
{
	int	fdi_to_return;

	fdi_to_return = -2;
	if (exec_info->next_type != LAST)
	{
		fdi_to_return = fd_pipe[0];
		close(fd_pipe[1]);
		return (fdi_to_return);
	}
	return (fdi_to_return);
}

static int	ft_open(t_exec *exec_info, int i)
{
	int	file;

	if (exec_info[i - 1].next_type == REDIRECT_TO_DOUBLE)
		file = open(exec_info[i].cmd, O_CREAT | O_APPEND | O_RDWR, 0644);
	else if (exec_info[i - 1].next_type == REDIRECT_TO_SINGLE)
		file = open(exec_info[i].cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (file);
}

static int	ft_redirect_to_init(t_exec *exec_info, int fd[2], int fdi, int i)
{
	int	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		if (fdi > 0)
		{
			dup2(fdi, STDIN_FILENO);
			close(fdi);
		}
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execute_cmd(&(exec_info[i]), 0);
	}
	close(fd[1]);
	return (pid);
}

static int	ft_redirect_to_last(t_exec *exec_info, int fd[2], int i)
{
	char	line;
	int		file;
	int		fdi_to_return;
	int		fd_pipe[2];

	file = ft_open(exec_info, i);
	if (!(exec_info[i].next_type == REDIRECT_TO_SINGLE
			|| exec_info[i].next_type == REDIRECT_TO_DOUBLE))
	{
		if (exec_info[i].next_type != LAST)
			pipe(fd_pipe);
		while (read(fd[0], &line, 1))
		{
			write(file, &line, 1);
			if (exec_info[i].next_type != LAST)
				write(fd_pipe[1], &line, 1);
		}
		fdi_to_return = verify_last_pipe(&exec_info[i], fd_pipe);
		close(fd[0]);
	}
	close(file);
	return (fdi_to_return);
}

void	ft_redirect_to(t_exec *exec_info, int i, int fdi)
{
	static int		fd[2];
	int				pid;
	int				fdi_to_send;

	if (i == 0 || fdi == -2 || (fdi >= 0 && exec_info[i - 1].next_type == PIPE))
		pid = ft_redirect_to_init(exec_info, fd, fdi, i);
	else
	{
		if (fdi >= 0)
			fd[0] = fdi;
		fdi_to_send = ft_redirect_to_last(exec_info, fd, i);
	}
	if (exec_info[i].next_type == REDIRECT_TO_SINGLE
		|| exec_info[i].next_type == REDIRECT_TO_DOUBLE)
		ft_redirect_to(exec_info, i + 1, -1);
	else if (exec_info[i].next_type != LAST)
		ft_redirects(exec_info, i + 1, fdi_to_send, -1);
	if (i == 0 || fdi == -2 || (fdi >= 0 && exec_info[i - 1].next_type == PIPE))
		ft_wait_get_status(pid, 0);
}
