/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:12:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/30 23:43:09 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_parser_args(char *line, int i, t_exec *exec, int k)
{
	int	j;

	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\t')
		j++;
	if (j != i)
		exec->args[k] = ft_substr(line, i, j - i);
	else
		exec->args[k] = '\0';
	return (j);
}

int	ft_parser_exec(char *line, t_exec *exec)
{
	int		i;
	int		j;
	int		k;

	exec->next_type = LAST;
	exec->args = malloc(40 * sizeof(char *));
	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	j = i;
	while (line[j] && line[j] != ' ' && line[j] != '\t')
		j++;
	exec->cmd = ft_substr(line, i, j - i);
	k = 0;
	while (line[j])
	{
		j = ft_parser_args(line, j, exec, k);
		k++;
	}
	exec->args[k] = '\0';
	return (exec->next_type);
}

void	ft_free_parser(t_exec *exec)
{
	int	i;

	i = -1;
	if (exec->args)
		while (exec->args[++i])
			free(exec->args[i]);
	free(exec->cmd);
	free(exec->args);
	free(exec);
}

void	ft_parser(char *line, t_exec *exec_info)
{
	ft_parser_exec(line, &exec_info[0]);
}
