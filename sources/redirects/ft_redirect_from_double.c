/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_from_double.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 23:03:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/27 15:25:44 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_redire_from_doub_init(int fd[2], t_exec *exc_inf, int pid, int i)
{
	char	*line;

	if (pid == 0)
	{
		if (exc_inf[i - 1].next_type == REDIRECT_FROM_SINGLE)
		{
			if (check_path(&exc_inf[i]))
				ft_redirect_from_single_init(&exc_inf[i], fd);
			close(fd[1]);
			return ;
		}
		signal(SIGINT, handle_standard);
		while (1)
		{
			line = readline("> ");
			if (not_have_line(&exc_inf[i], line))
				break ;
			if (!ft_strncmp(exc_inf[i].cmd, line, ft_strlen(exc_inf[i].cmd))
				&& ft_strlen(exc_inf[i].cmd) == ft_strlen(line))
				break ;
			write(fd[1], line, ft_strlen(line));
			write(fd[1], "\n", 1);
		}
		close(fd[1]);
	}
}

static void	ft_redirect_from_double_middle(t_exec *exec_info, int pid, int i)
{
	char	*line;

	if (pid == 0)
	{
		if (exec_info[i - 1].next_type == REDIRECT_FROM_SINGLE)
		{
			check_path(&exec_info[i]);
			return ;
		}
		signal(SIGINT, handle_standard);
		while (1)
		{
			line = readline("> ");
			if (!line)
			{
				printf("warning: wanted %s\n", exec_info[i].cmd);
				break ;
			}
			if (!ft_strncmp(exec_info[i].cmd, line, ft_strlen(exec_info[i].cmd))
				&& ft_strlen(exec_info[i].cmd) == ft_strlen(line))
				break ;
		}
	}
}

int	ft_redi_from_doub_last(t_exec *ex_inf, int fd[2], int pid, int fdt)
{
	if (pid == 0)
	{
		signal(SIGINT, handle_standard);
		if (fdt >= 0)
		{
			dup2(fdt, STDOUT_FILENO);
			close(fdt);
		}
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		ft_execute_cmd(ex_inf, 0);
	}
	close(fd[0]);
	close(fd[1]);
	if (fdt >= 0)
		close(fdt);
	ft_wait_get_status(pid, 0);
	return (0);
}

static int	ft_redirect_setup(t_exec *exec_info, int fd[2],
								int fd_to[2], int *commands)
{
	int	pid;

	signal(SIGINT, handle_nothing);
	pipe(fd);
	pipe(fd_to);
	pid = fork();
	if (!(*commands == 0 || exec_info[*commands - 1].next_type == PIPE))
		(*commands)--;
	while (exec_info[++(*commands)].next_type == REDIRECT_FROM_DOUBLE
		|| exec_info[*commands].next_type == REDIRECT_FROM_SINGLE)
		ft_redirect_from_double_middle(exec_info, pid, *commands);
	ft_redire_from_doub_init(fd, exec_info, pid, *commands);
	return (pid);
}

void	ft_redirect_from_double(t_exec *exec_info, int i, int pid, int commands)
{
	int	fd[2];
	int	fd_to[2];

	pid = ft_redirect_setup(exec_info, fd, fd_to, &commands);
	if ((i == 0 || exec_info[i - 1].next_type == PIPE) && exec_info->cmd[0])
	{
		if (exec_info[commands].next_type != LAST
			&& (ft_redi_from_doub_last(&(exec_info[i]), fd, pid, fd_to[1])
				|| ft_signals() || 1))
			ft_redirects(exec_info, commands + 1, fd_to[0], 1);
		else
			check_pipe_and_last(&(exec_info[i]), fd, pid, fd_to[0]);
	}
	else
	{
		if (pid == 0)
			exit(EXIT_SUCCESS);
		if (exec_info[commands].next_type != LAST
			&& (ft_redi_from_doub_last(&(exec_info[i]), fd, pid, fd_to[1])
				|| ft_signals() || 1))
			ft_redirects(exec_info, commands + 1, fd_to[0], 1);
		else
			wait_and_handle_sig(pid);
	}
}
