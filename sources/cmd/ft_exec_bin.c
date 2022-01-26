/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 20:15:34 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/26 18:28:20 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	**new_array(char *cmd, char **args)
{
	int		count_args;
	int		count_array;
	char	**new_array;

	count_args = 0;
	while (args[count_args])
		count_args++;
	new_array = (char **)ft_calloc(sizeof(char *), count_args + 2);
	new_array[0] = cmd;
	count_args = 0;
	count_array = 1;
	while (args[count_args])
	{
		new_array[count_array] = args[count_args];
		count_args++;
		count_array++;
	}
	return (new_array);
}

static char	**ft_join_cmd(char *cmd)
{
	char	**paths;
	char	**new_paths;
	char	*temp;
	int		i;
	int		n_paths;

	i = -1;
	temp = ft_strjoin("/", cmd);
	paths = ft_split(ft_get_env("PATH"), ':');
	if (!paths)
	{
		free(temp);
		return (NULL);
	}
	n_paths = 0;
	while (paths && paths[n_paths])
		n_paths++;
	new_paths = (char **)ft_calloc(sizeof(char *), n_paths + 1);
	while (paths && paths[++i])
		new_paths[i] = ft_strjoin(paths[i], temp);
	free(temp);
	ft_free_array(paths);
	return (new_paths);
}

static void	ft_exec(char *cmd, char **arguments, char **envp)
{
	char	**paths;
	int		i;

	if (execve(cmd, arguments, envp))
	{
		paths = ft_join_cmd(cmd);
		if (paths)
		{
			i = -1;
			while (paths[++i])
				if (!access(paths[i], X_OK))
					break ;
			if (execve(paths[i], arguments, envp))
				ft_putstr_fd("somenthing was wrong!\n", 2);
			ft_free_array(paths);
		}
		else
			ft_putstr_fd("somenthing was wrong!\n", 2);
		ft_free_array(arguments);
	}
}

void	ft_exec_bin(char *cmd, char **args, int shouldfork)
{
	char	**envp;
	char	**new_args;
	int		pid;

	pid = 0;
	if (shouldfork)
		pid = fork();
	if (pid == 0)
	{
		new_args = new_array(cmd, args);
		envp = ft_join_envs();
		ft_exec(cmd, new_args, envp);
		ft_free_array(envp);
		exit(127);
	}
	else
		ft_wait_get_status(pid, 1);
}
