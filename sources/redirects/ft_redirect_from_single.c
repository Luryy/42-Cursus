/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_single.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:07:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/19 19:58:00 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	check_path(t_exec *exec_info)
{
	if (open(exec_info->cmd, O_RDONLY) < 0)
	{
		printf("%s: No such file or directory\n", exec_info->cmd);
		return (0);
	}
	return (1);
}

static void	ft_redirect_from_single_init(t_exec *exec_info, int fd[2])
{
	int		pid;
	int		file_fd;
	char	line;

	pid = fork();
	if (pid == 0)
	{
		file_fd = open(exec_info->cmd, O_RDONLY);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		while (read(file_fd, &line, 1))
			write(1, &line, 1);
		close(file_fd);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	waitpid(pid, NULL, 0);
}

static void	ft_redirect_from_single_last(t_exec *exec_info, int fd[2])
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

void	ft_redirect_from_single(t_exec *exec_info)
{
	int		fd[2];
	int		comands;

	comands = 0;
	while (exec_info[comands].next_type == REDIRECT_FROM_SINGLE)
	{
		if (!check_path(&exec_info[comands + 1]))
			return ;
		comands++;
	}
	pipe(fd);
	ft_redirect_from_single_init(&exec_info[comands], fd);
	ft_redirect_from_single_last(exec_info, fd);
}
