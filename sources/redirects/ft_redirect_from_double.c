/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:03:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/24 21:21:51 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_redirect_from_double_init(int fd[2], char *eof, int pid)
{
	char	*line;

	if (pid == 0)
	{
		signal(SIGINT, handle_standard);
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				printf("warning: wanted %s\n", eof);
				break ;
			}
			if (!ft_strncmp(eof, line, ft_strlen(eof))
				&& ft_strlen(eof) == ft_strlen(line))
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
		}
		close(fd[1]);
	}
}

static void	ft_redirect_from_double_middle(char *eof, int pid)
{
	char	*line;

	if (pid == 0)
	{
		signal(SIGINT, handle_standard);
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				printf("warning: wanted %s\n", eof);
				break ;
			}
			if (!ft_strncmp(eof, line, ft_strlen(eof))
				&& ft_strlen(eof) == ft_strlen(line))
				break ;
		}
	}
}

static int	ft_redi_from_doub_last(t_exec *ex_inf, int fd[2], int pid, int cmd)
{
	int	fd_to_return[2];
	int	fdi_to_return;

	fdi_to_return = -1;
	if (ex_inf[cmd].next_type != LAST && pid != 0)
	{
		pipe(fd_to_return);
		fdi_to_return = fd_to_return[0];
	}
	if (pid == 0)
	{
		signal(SIGINT, handle_standard);
		if (ex_inf[cmd].next_type != LAST)
		{
			dup2(fd_to_return[1], STDOUT_FILENO);
			close(fd_to_return[1]);
			close(fd_to_return[0]);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_execute_cmd(ex_inf, 0);
	}
	close(fd[0]);
	close(fd[1]);
	if (ex_inf[cmd].next_type != LAST)
		close(fd_to_return[1]);
	waitpid(pid, NULL, 0);
	return (fdi_to_return);
}

void	ft_redirect_from_double(t_exec *exec_info, int i)
{
	int	fd[2];
	int	pid;
	int	commands;
	int	fdi_to;

	commands = i;
	signal(SIGINT, handle_nothing);
	pipe(fd);
	pid = fork();
	while (exec_info[++commands].next_type == REDIRECT_FROM_DOUBLE)
		ft_redirect_from_double_middle(exec_info[commands].cmd, pid);
	ft_redirect_from_double_init(fd, exec_info[commands].cmd, pid);
	fdi_to = ft_redi_from_doub_last(&(exec_info[i]), fd, pid, commands - i);
	ft_signals();
	if (exec_info[commands].next_type != LAST)
	{
		ft_redirects(exec_info, commands + 1, fdi_to, -1);
	}
}
