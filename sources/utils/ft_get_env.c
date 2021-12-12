/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 20:40:25 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/12 14:51:35 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_get_env(char *env)
{
	t_env	*envs;

	envs = (mini_s()->envs);
	while (envs->next != NULL)
	{
		if (!ft_strncmp(env, envs->key, ft_strlen(env)))
			return (envs->value);
		envs = envs->next;
	}
	return (NULL);
}
