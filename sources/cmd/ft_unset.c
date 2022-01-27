/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:01:55 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 17:43:54 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_unset(char **args)
{
	t_env	*temp;
	int		count_args;

	count_args = 0;
	while (args[count_args])
	{
		temp = mini_s()->envs;
		while (temp)
		{
			if (!ft_strncmp(args[count_args], temp->key,
					ft_strlen(args[count_args]))
				&& ft_strlen(args[count_args]) == ft_strlen(temp->key))
				temp->visible = 0;
			temp = temp->next;
		}
		count_args++;
	}
}
