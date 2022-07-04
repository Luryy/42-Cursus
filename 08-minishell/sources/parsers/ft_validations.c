/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validations.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 18:08:21 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/27 19:16:31 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_verify_quote(char *line, int *i, char quote)
{
	if (line[*i] == quote)
	{
		if (line[++(*i)])
		{
			while (line[*i] && line[*i] != quote)
				(*i)++;
			if (line[*i] == quote)
				return (0);
			else
			{
				(*i)--;
				return (1);
			}
		}
		else
			return (1);
	}
	return (0);
}

int	ft_validate_quotes(char *line)
{
	int	i;
	int	unclosed_quotes;

	i = 0;
	unclosed_quotes = 0;
	while (unclosed_quotes == 0 && line[i])
	{
		unclosed_quotes += ft_verify_quote(line, &i, '\'');
		if (unclosed_quotes == 0)
			unclosed_quotes += ft_verify_quote(line, &i, '\"');
		i++;
	}
	if (unclosed_quotes != 0)
	{
		ft_putstr_fd("close your quotes\n", 2);
		mini_s()->last_exec_code = 1;
		return (1);
	}
	return (0);
}

int	ft_validate_redirects(t_exec *exec_info)
{
	int	i;

	i = -1;
	while (exec_info[++i].next_type != LAST)
	{
		if (!exec_info[i + 1].cmd[0])
		{
			ft_putstr_fd("parse error\n", 2);
			mini_s()->last_exec_code = 1;
			return (1);
		}
	}
	return (0);
}
