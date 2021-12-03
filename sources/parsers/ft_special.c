/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_special.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 22:28:52 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/03 17:37:57 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static void	ft_parse_double_quotes(char *line, int *init_arg)
{
	if (line[*init_arg] == '\"' && line[++(*init_arg)])
	{
		while (line[*init_arg + 1] && line[*init_arg + 1] != '\"')
			(*init_arg)++;
		(*init_arg)++;
	}
}

static void	ft_parse_single_quotes(char *line, int *init_arg)
{
	if (line[*init_arg] == '\'' && line[++(*init_arg)])
	{
		while (line[*init_arg + 1] && line[*init_arg + 1] != '\'')
			(*init_arg)++;
		(*init_arg)++;
	}
}

static void	ft_parse_redirect(char *line, int *init_arg, t_exec *exec)
{
	if (line[*init_arg] == '|')
		exec->next_type = PIPE;
	else if (line[*init_arg] == '>')
	{
		if (line[*init_arg + 1] && line[*init_arg + 1] == '>' && (*init_arg)++)
			exec->next_type = REDIRECT_TO_DOUBLE;
		else
			exec->next_type = REDIRECT_TO_SINGLE;
	}
	else if (line[*init_arg] == '<')
	{
		if (line[*init_arg + 1] && line[*init_arg + 1] == '<' && (*init_arg)++)
			exec->next_type = REDIRECT_FROM_DOUBLE;
		else
			exec->next_type = REDIRECT_FROM_SINGLE;
	}
}

void	ft_parse_special(char *line, int *init_arg, t_exec *exec)
{
	int	comparer;

	comparer = *init_arg;
	ft_parse_double_quotes(line, init_arg);
	if (comparer == *init_arg)
		ft_parse_single_quotes(line, init_arg);
	if (comparer == *init_arg)
		ft_parse_redirect(line, init_arg, exec);
	(*init_arg)++;
}
