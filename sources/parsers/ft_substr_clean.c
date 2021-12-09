/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:30:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/09 23:51:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_env_name(int *line_len, int *line_ref, char *line)
{
	int		i;
	char	*env_name;

	i = -1;
	(*line_len) = 1;
	env_name = malloc(100 * sizeof(char));
	while (line[(*line_ref)] != '\"' && line[(*line_ref)] != '\''
		&& line[++(*line_ref)] && line[(*line_ref)] != ' ' && (*line_len)++)
		env_name[++i] = line[*line_ref];
	env_name[++i] = '\0';
	return (env_name);
}

static int	ft_includ_env(int *line_ref, char *line, int *arg_ref, char *arg)
{
	char	*env_name;
	char	*env_var;
	int		line_len;
	int		env_len;
	int		i;

	env_len = 0;
	env_name = ft_get_env_name(&line_len, line_ref, line);
	env_var = ft_get_env(env_name);
	free(env_name);
	i = -1;
	if (env_var)
		while (env_var[++i] && ++env_len)
			arg[(*arg_ref)++] = env_var[i];
	else if (++env_len)
		arg[(*arg_ref)++] = ' ';
	(*line_ref)--;
	return (env_len - line_len);
}

static char	*ft_parse_str_env(char *line, int init_arg, int len, int *parsed_le)
{
	char	*arg_line;
	int		line_ref;
	int		arg_ref;

	line_ref = -1;
	arg_ref = 0;
	arg_line = malloc(10000 * sizeof(char));
	*parsed_le = len;
	while (line[++line_ref])
	{
		if (line[line_ref] == '$' && line_ref >= init_arg
			&& line_ref < init_arg + len)
			*parsed_le += ft_includ_env(&line_ref, line, &arg_ref, arg_line);
		else
			arg_line[arg_ref++] = line[line_ref];
	}
	return (arg_line);
}

char	*ft_substr_clean(char *line, int init_arg, int len)
{
	char	*arg_line;
	char	*final_line;
	int		parsed_len;

	arg_line = ft_parse_str_env(line, init_arg, len, &parsed_len);
	if (line[init_arg] == '<' || line[init_arg] == '>' || line[init_arg] == '|')
		final_line = '\0';
	else if (line[init_arg] == '\"' || line[init_arg] == '\'')
		final_line = ft_substr(arg_line, init_arg + 1, parsed_len - 2);
	else
		final_line = ft_substr(arg_line, init_arg, parsed_len);
	free(arg_line);
	return (final_line);
}
