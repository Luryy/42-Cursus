/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:41:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/24 19:44:27 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_execute(char *line)
{
	if (!line)
	{
		printf("exit\n");
		exit(EXIT_SUCCESS);
	}
	if (!ft_strncmp(line, "echo", 4))
		printf("TODO - exec: echo");
		// ft_echo();
	else if (!ft_strncmp(line, "cd", 2))
		printf("TODO - exec: cd");
		// ft_cd();
	else if (!ft_strncmp(line, "pwd", 3))
		ft_pwd();
	else if (!ft_strncmp(line, "export", 6))
		printf("TODO - exec: export");
		// ft_export();
	else if (!ft_strncmp(line, "unset", 5))
		printf("TODO - exec: unset");
		// ft_unset();
	else if (!ft_strncmp(line, "env", 3))
		printf("TODO - exec: env");
		// ft_env();
	else if (!ft_strncmp(line, "exit", 4))
		printf("TODO - exec: exit");
		// ft_exit();
	else
		printf("TODO - exec: bin");
		// exec_bin();
}
