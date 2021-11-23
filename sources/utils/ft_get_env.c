/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:40:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/23 20:46:39 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	ft_get_env(char *env, char **envp)
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
