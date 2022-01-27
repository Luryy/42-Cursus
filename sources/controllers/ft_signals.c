/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signals.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:19:57 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/27 10:46:13 by lyuri-go         ###   ########.fr       */
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
		mini_s()->last_exec_code = 130;
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
		exit(130);
	}
}

void	ft_signals_standard_exec(int sig)
{
	if (sig == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		mini_s()->last_exec_code = 130;
	}
	if (sig == SIGQUIT)
	{
		ft_putendl_fd("Quit", 2);
		mini_s()->last_exec_code = 131;
	}
}
