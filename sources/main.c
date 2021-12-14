/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:26:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/10 20:50:51 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	main(int argc, char **argv, char **envp)
{
	char	*line;

	(void)argc;
	(void)argv;
	ft_parser_envs(envp);
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
