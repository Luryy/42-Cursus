/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:16:46 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/12 14:53:08 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	find_and_change_var(char *key, char *value)
{
	t_env	*temp;

	temp = mini_s()->envs;
	while (temp->next != NULL)
	{
		if (!ft_strncmp(key, temp->key, ft_strlen(key)))
		{
			free(key);
			key = NULL;
			free(temp->value);
			temp->value = NULL;
			temp->value = value;
			return (1);
		}
		temp = temp->next;
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
		value = ft_substr(args[count_args], split + 1,
				ft_strlen(args[count_args]));
		if (find_and_change_var(key, value))
			return ;
		ft_env_add_front(&mini_s()->envs, ft_new_node(key, value, 1));
		count_args++;
	}
}
