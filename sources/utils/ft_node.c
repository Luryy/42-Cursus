/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:50:37 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/12 14:51:47 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env_add_front(t_env **envs, t_env *new)
{
	if (!envs)
		return ;
	new->next = *envs;
	*envs = new;
}

t_env	*ft_new_node(char *key, char *value, int visible)
{
	t_env	*node;

	node = (t_env *)ft_calloc(sizeof(t_env), 1);
	node->key = key;
	node->value = value;
	node->visible = visible;
	node->next = NULL;
	return (node);
}
