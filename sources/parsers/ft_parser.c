/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:12:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/03 17:39:47 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	ft_parser_args(char *line, int init_arg, t_exec *exec, int arg_nb)
{
	int	end_arg;

	while (line[init_arg] == ' ' || line[init_arg] == '\t')
		init_arg++;
	end_arg = init_arg;
	while (line[end_arg] && line[end_arg] != ' ' && line[end_arg] != '\t')
		ft_parse_special(line, &end_arg, exec);
	if (end_arg != init_arg)
		exec->args[arg_nb] = ft_substr(line, init_arg, end_arg - init_arg);
	else
		exec->args[arg_nb] = '\0';
	return (end_arg);
}

int	ft_parser_exec(char *line, t_exec *exec, int *str_init)
{
	int	str_end;
	int	args_counter;

	exec->next_type = LAST;
	exec->args = malloc(40 * sizeof(char *));
	while (line[*str_init] == ' ' || line[*str_init] == '\t')
		(*str_init)++;
	str_end = *str_init;
	while (line[str_end] && line[str_end] != ' ' && line[str_end] != '\t')
		str_end++;
	exec->cmd = ft_substr(line, *str_init, str_end - *str_init);
	args_counter = 0;
	while (line[str_end] && exec->next_type == LAST)
	{
		str_end = ft_parser_args(line, str_end, exec, args_counter);
		args_counter++;
	}
	exec->args[args_counter] = '\0';
	*str_init = str_end;
	return (exec->next_type);
}

void	ft_free_parser(t_exec *exec)
{
	int	i;
	int	j;

	i = -1;
	while (exec[++i].cmd)
	{
		j = -1;
		if (exec[i].args)
			while (exec[i].args[++j])
				free(exec[i].args[j]);
		free(exec[i].cmd);
		free(exec[i].args);
	}
	free(exec);
}

void	ft_parser(char *line, t_exec *exec_info)
{
	int	i;
	int	starter;

	i = 0;
	starter = 0;
	while (ft_parser_exec(line, &(exec_info[i]), &starter))
		i++;
	exec_info[i + 1].cmd = '\0';
}
