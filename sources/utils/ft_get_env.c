/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:40:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/26 19:43:08 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_get_env(char *env)
{
	t_env	*envs;
	size_t	env_len;

	envs = (mini_s()->envs);
	env_len = ft_strlen(env);
	while (envs->next != NULL)
	{
		if (!ft_strncmp(env, envs->key, env_len)
			&& ft_strlen(envs->key) == env_len)
		{
			if (envs->visible == 0)
				return (NULL);
			return (envs->value);
		}
		if (!ft_strncmp(env, "?", 1) && 1 == env_len)
			return (ft_itoa(mini_s()->last_exec_code));
		envs = envs->next;
	}
	return (NULL);
}
