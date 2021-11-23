/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:40:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/23 21:34:46 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_get_env_nb(char *env, char **envp)
{
	int	i;
	int	len;

	len = ft_strlen(env);
	i = -1;
	while (envp[++i])
	{
		if (!ft_strncmp(env, envp[i], len) && envp[i][len] == '=')
			return (i);
	}
	return (-1);
}

char	*ft_get_env(char *env)
{
	int		i;
	int		j;
	char	**envp;

	envp = mini_s()->envs;
	i = ft_get_env_nb(env, envp);
	if (i >= 0)
	{
		j = 0;
		while (envp[i][j] != '=' && envp[i][j])
			j++;
		j++;
		return (&envp[i][j]);
	}
	return (NULL);
}
