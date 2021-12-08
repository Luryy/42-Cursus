/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 20:16:46 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/08 20:46:34 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void    ft_export(char **args)
{
    t_mini *mini;
    int i;

    i = 0;
    mini = mini_s();
    while (mini->envs[i])
	{
        i++;
	}
	mini->envs[i] = ft_strdup(args[0]);
	i++;
	mini->envs[i] = '\0';
}
