/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_envs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:40:18 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/12 14:51:08 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_free_env(void)
{
	t_env	*current;
	t_env	*next;

	current = mini_s()->envs;
	while (current != NULL)
	{
		next = current->next;
		free(current->key);
		free(current->value);
		free(current);
		current = next;
	}
}

static void	fill_envs(t_env **envs, char *key, char *value)
{
	ft_env_add_front(envs, ft_new_node(key, value, 1));
}

int	split_key(char *env)
{
	int	i;

	i = -1;
	while (env[++i])
	{
		if (env[i] == '=')
			return (i);
	}
	return (0);
}

void	ft_parser_envs(char **envp)
{
	int		count_env;
	int		split;
	char	*key;
	char	*value;

	count_env = -1;
	split = 0;
	while (envp[++count_env])
	{
		split = split_key(envp[count_env]);
		key = ft_substr(envp[count_env], 0, split);
		value = ft_substr(envp[count_env], split + 1, strlen(envp[count_env]));
		fill_envs(&mini_s()->envs, key, value);
	}
}
