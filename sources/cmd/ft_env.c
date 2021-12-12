/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:31:42 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/10 21:09:06 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(void)
{
	t_env	*temp;

	temp = mini_s()->envs;
	while (temp->next != NULL)
	{
		printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
