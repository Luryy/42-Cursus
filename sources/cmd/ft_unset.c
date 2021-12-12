/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:01:55 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/12 15:14:39 by elima-me         ###   ########.fr       */
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
		while (temp->next != NULL)
		{
			if (!ft_strncmp(args[count_args], temp->key,
					ft_strlen(args[count_args])))
				temp->visible = 0;
			temp = temp->next;
		}
		count_args++;
	}
}
