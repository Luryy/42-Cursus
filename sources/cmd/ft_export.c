/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:16:46 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 17:43:59 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	find_and_change_var(char *key, char *value)
{
	t_env	*temp;
	size_t	key_n;

	temp = mini_s()->envs;
	key_n = ft_strlen(key);
	while (temp)
	{
		if (!ft_strncmp(key, temp->key, key_n) && key_n == ft_strlen(temp->key))
		{
			free(key);
			key = NULL;
			free(temp->value);
			temp->value = NULL;
			temp->value = value;
			temp->visible = 1;
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

static int	ft_validate_key(char *key)
{
	int	i;

	i = 0;
	if (!ft_isalpha(key[i]))
		return (1);
	while (key[++i])
	{
		if (!ft_isalnum(key[i]) && key[i] != '_')
			return (1);
	}
	return (0);
}

void	ft_export(char **args)
{
	int		count_args;
	int		split;
	char	*key;
	char	*value;

	count_args = 0;
	while (args[count_args])
	{
		split = split_key(args[count_args]);
		key = ft_substr(args[count_args], 0, split);
		if (ft_validate_key(key))
		{
			ft_putstr_fd("export: not a valid identifier\n", 2);
			mini_s()->last_exec_code = 1;
			count_args++;
			continue ;
		}
		value = ft_substr(args[count_args], split + 1,
				ft_strlen(args[count_args]));
		if (find_and_change_var(key, value))
			return ;
		ft_env_add_front(&mini_s()->envs, ft_new_node(key, value, 1));
		count_args++;
	}
}
