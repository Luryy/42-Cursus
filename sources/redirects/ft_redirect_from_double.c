/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:03:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/19 01:10:18 by lyuri-go         ###   ########.fr       */
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

static void	ft_redirect_from_double_last(t_exec *exec_info, int fd[2], int pid)
{
	if (pid == 0)
	{
		signal(SIGINT, handle_standard);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_execute_cmd(exec_info, 0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
}

void	ft_redirect_from_double(t_exec *exec_info, int i)
{
	int	fd[2];
	int	pid;

	signal(SIGINT, handle_nothing);
	pipe(fd);
	pid = fork();
	while (exec_info[++i].next_type == REDIRECT_FROM_DOUBLE)
		ft_redirect_from_double_middle(exec_info[i].cmd, pid);
	ft_redirect_from_double_init(fd, exec_info[i].cmd, pid);
	ft_redirect_from_double_last(exec_info, fd, pid);
	ft_signals();
}
