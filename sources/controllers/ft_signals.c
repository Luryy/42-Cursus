/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:19:57 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/19 00:34:41 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	handle(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (sig == SIGQUIT)
		printf("\b\b  \b\b");
}

void	ft_signals(void)
{
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
}

void	handle_nothing(int sig)
{
	(void)sig;
}

void	handle_standard(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		exit(EXIT_SUCCESS);
	}
}
