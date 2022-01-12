/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to_double.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 23:58:26 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/11 21:48:08 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_open(t_exec *exec_info)
{
	int	file;

	if (exec_info->next_type == REDIRECT_TO_DOUBLE)
		file = open(exec_info[1].cmd, O_CREAT | O_APPEND | O_RDWR, 0644);
	else if (exec_info->next_type == REDIRECT_TO_SINGLE)
		file = open(exec_info[1].cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	return (file);
}

void	ft_redirect_to_double(t_exec *exec_info)
{
	int		fd[2];
	int		pid;
	int		file;
	char	line;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execute_cmd(exec_info, 0);
	}
	else
	{
		close(fd[1]);
		file = ft_open(exec_info);
		while (read(fd[0], &line, 1))
			write(file, &line, 1);
		close(file);
		close(fd[0]);
	}
	waitpid(pid, NULL, 0);
}

// void	ft_redirect_to_double(t_exec *exec_info)
// {
	// int		fd[2];
	// int		pid;
	// int		fd_open;
	// char	line;
// 
	// pipe(fd);
	// pid = fork();
	// if (pid == 0)
	// {
		// dup2(fd[1], STDOUT_FILENO);
		// close(fd[0]);
		// close(fd[1]);
		// ft_execute_cmd(exec_info, 0);
	// }
	// else
	// {
		// close(fd[1]);
		// fd_open = open(exec_info[1].cmd, O_CREAT | O_APPEND | O_RDWR, 0644);
		// while (read(fd[0], &line, 1))
			// write(fd_open, &line, 1);
		// close(fd_open);
		// close(fd[0]);
	// }
	// waitpid(pid, NULL, 0);
// }
