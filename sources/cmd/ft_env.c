/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:31:42 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 17:44:03 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(void)
{
	t_env	*temp;

	temp = mini_s()->envs;
	while (temp)
	{
		if (temp->visible == 1)
			printf("%s=%s\n", temp->key, temp->value);
		temp = temp->next;
	}
}
