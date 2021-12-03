/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:31:42 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/02 18:41:52 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_env(void)
{
	t_mini	*mini;
	int		i;

	mini = mini_s();
	i = -1;
	while (mini->envs[++i])
	{
		ft_putstr_fd(mini->envs[i], 1);
		ft_putchar_fd('\n', 1);
	}
}
