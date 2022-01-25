/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_single.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 19:07:38 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/25 14:40:21 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	check_path(t_exec *exec_info)
{
	int	fd;

	fd = open(exec_info->cmd, O_RDONLY);
	close(fd);
	if (fd < 0)
	{
		printf("%s: No such file or directory\n", exec_info->cmd);
		return (0);
	}
	return (1);
}

void	ft_redirect_from_single_init(t_exec *exec_info, int fd[2])
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

static int	ft_redirect_from_single_last(t_exec *exec_info, int fd[2], int last)
{
	int	pid2;
	int	fd_to[2];

	close(fd[1]);
	if (!last)
		pipe(fd_to);
	pid2 = fork();
	if (pid2 == 0)
	{
		if (!last)
		{
			dup2(fd_to[1], STDOUT_FILENO);
			close(fd_to[0]);
			close(fd_to[1]);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_execute_cmd(exec_info, 0);
	}
	close(fd[0]);
	waitpid(pid2, NULL, 0);
	if (last)
		return (-1);
	close(fd_to[1]);
	return (fd_to[0]);
}

static int	ft_verify_redirect(t_exec *exec_info, int i, int *comands)
{
	*comands = i;
	if (i > 1 && (exec_info[i - 2].next_type == REDIRECT_TO_SINGLE
			|| exec_info[i - 2].next_type == REDIRECT_TO_DOUBLE))
	{
		while (exec_info[i].next_type == REDIRECT_FROM_SINGLE
				|| exec_info[i].next_type == LAST)
		{
			if (!check_path(&exec_info[i]))
				return (1);
			i++;
		}
		return (1);
	}
	while (exec_info[*comands].next_type == REDIRECT_FROM_SINGLE)
		if (!check_path(&exec_info[++(*comands )]))
			return (1);
	return (0);
}

void	ft_redirect_from_single(t_exec *exec_info, int i)
{
	int		fd[2];
	int		comands;
	int		fdi;

	if (ft_verify_redirect(exec_info, i, &comands))
	{
		while (exec_info[comands].next_type == REDIRECT_FROM_SINGLE)
			comands++;
		if (exec_info[comands].next_type != LAST)
			ft_redirects(exec_info, comands, -1, -1);
		return;
	}
	pipe(fd);
	ft_redirect_from_single_init(&exec_info[comands], fd);
	if (exec_info[comands].next_type == LAST)
		ft_redirect_from_single_last(&exec_info[i], fd, 1);
	else
	{
		fdi = ft_redirect_from_single_last(&exec_info[i], fd, 0);
		ft_redirects(exec_info, comands + 1, fdi, -1);
	}
}
