/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:47:10 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/10 21:01:38 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_free(t_exec *exec)
{
	if (exec)
		ft_free_parser(exec);
	if (mini_s()->envs)
		ft_free_env();
}
