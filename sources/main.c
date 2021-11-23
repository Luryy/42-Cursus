/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:26:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/23 21:34:12 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	*line;
	t_mini	*mini;

	(void)argc;
	(void)argv;
	mini = mini_s();
	mini->envs = envp;
	ft_signals();
	ft_load_history();
	while (1)
	{
		line = readline("minishell > ");
		ft_execute(line);
		ft_add_history(line);
	}
	return (0);
}
