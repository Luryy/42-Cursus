/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:50:11 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 19:39:42 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	chdir_safe(char *path, int should_fork)
{
	if (path[0] == '~' && !path[1])
	{
		ft_parse_home(should_fork);
		return ;
	}
	if (chdir(path) == -1)
	{
		ft_putstr_fd("No such file or directory\n", 1);
		if (!should_fork)
			exit(1);
		mini_s()->last_exec_code = 1;
		return ;
	}
	if (!should_fork)
		exit(0);
	mini_s()->last_exec_code = 0;
	return ;
}

void	ft_parse_home(int should_fork)
{
	char	*home_path;

	home_path = ft_get_env("HOME");
	if (!home_path)
	{
		ft_putstr_fd("cd: HOME not set\n", 2);
		if (!should_fork)
			exit(1);
		mini_s()->last_exec_code = 1;
		return ;
	}
	else
		chdir_safe(home_path, should_fork);
}

void	ft_cd(char **path, int should_fork)
{
	int		path_len;

	path_len = 0;
	while (path[path_len])
		path_len++;
	if (path_len > 1)
	{
		ft_putstr_fd("too many arguments\n", 2);
		if (!should_fork)
			exit(1);
		mini_s()->last_exec_code = 1;
		return ;
	}
	if (path_len == 0)
		return (ft_parse_home(should_fork));
	chdir_safe(path[0], should_fork);
}
