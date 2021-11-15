/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 19:41:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/15 19:51:52 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_execute(char *line)
{
	if (!line)
		return ;
	if (!ft_strncmp(line, "echo", 4))
		ft_putstr_fd("TODO - exec: echo", 1);
		// ft_echo();
	else if (!ft_strncmp(line, "cd", 2))
		ft_putstr_fd("TODO - exec: cd", 1);
		// ft_cd();
	else if (!ft_strncmp(line, "pwd", 3))
		ft_putstr_fd("TODO - exec: pwd", 1);
		// ft_pwd();
	else if (!ft_strncmp(line, "export", 6))
		ft_putstr_fd("TODO - exec: export", 1);
		// ft_export();
	else if (!ft_strncmp(line, "unset", 5))
		ft_putstr_fd("TODO - exec: unset", 1);
		// ft_unset();
	else if (!ft_strncmp(line, "env", 3))
		ft_putstr_fd("TODO - exec: env", 1);
		// ft_env();
	else if (!ft_strncmp(line, "exit", 4))
		ft_putstr_fd("TODO - exec: exit", 1);
		// ft_exit();
	else
		ft_putstr_fd("TODO - exec: bin", 1);
		// exec_bin();
}
