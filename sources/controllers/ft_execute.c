/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:41:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/30 22:47:40 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_execute_cmd(t_exec exec)
{
	if (!ft_strncmp(exec.cmd, "echo", 4))
		ft_echo(exec.args);
	else if (!ft_strncmp(exec.cmd, "cd", 2))
		printf("TODO - exec: cd");
		// ft_cd();
	else if (!ft_strncmp(exec.cmd, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(exec.cmd, "export", 6))
		printf("TODO - exec: export");
		// ft_export();
	else if (!ft_strncmp(exec.cmd, "unset", 5))
		printf("TODO - exec: unset");
		// ft_unset();
	else if (!ft_strncmp(exec.cmd, "env", 3))
		printf("TODO - exec: env");
		// ft_env();
	else if (!ft_strncmp(exec.cmd, "exit", 4))
		printf("TODO - exec: exit");
		// ft_exit();
	else
		printf("TODO - exec: bin");
		// exec_bin();
}

void	ft_execute(char *line)
{
	t_exec	*exec_info;

	if (!line)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	exec_info = malloc(sizeof(t_exec) * 40);
	ft_parser(line, exec_info);
	ft_execute_cmd(exec_info[0]);
	ft_free_parser(exec_info);
}
