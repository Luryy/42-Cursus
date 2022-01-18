/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:03:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/19 00:04:48 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_redirect_from_double_init(int fd[2], char *eof)
{
	int		pid;
	char	*line;

	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		while (1)
		{
			line = readline("> ");
			if (!ft_strncmp(eof, line, ft_strlen(eof))
				&& ft_strlen(eof) == ft_strlen(line))
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
		}
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
}

static void	ft_redirect_from_double_middle(char *eof)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!ft_strncmp(eof, line, ft_strlen(eof))
			&& ft_strlen(eof) == ft_strlen(line))
			break ;
	}
}

static void	ft_redirect_from_double_last(t_exec *exec_info, int fd[2])
{
	int	pid2;

	pid2 = fork();
	if (pid2 == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execute_cmd(exec_info, 0);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid2, NULL, 0);
}

void	ft_redirect_from_double(t_exec *exec_info, int i)
{
	int	fd[2];

	pipe(fd);
	while (exec_info[++i].next_type == REDIRECT_FROM_DOUBLE)
		ft_redirect_from_double_middle(exec_info[i].cmd);
	ft_redirect_from_double_init(fd, exec_info[i].cmd);
	ft_redirect_from_double_last(exec_info, fd);
}
