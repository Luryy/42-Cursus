/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:19:57 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/25 20:03:57 by elima-me         ###   ########.fr       */
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

int	ft_signals(void)
{
	signal(SIGINT, handle);
	signal(SIGQUIT, handle);
	return (0);
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
