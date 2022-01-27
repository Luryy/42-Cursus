/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:30:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/27 10:21:13 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static char	*ft_get_env_name(int *line_len, int *line_ref, char *line)
{
	int		i;
	char	*env_name;

	i = -1;
	(*line_len) = 1;
	env_name = malloc(4000 * sizeof(char));
	while (line[++(*line_ref)] != '\"' && line[(*line_ref)] != '\''
		&& line[(*line_ref)] && line[(*line_ref)] != ' ' && (*line_len)++)
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
	i = -1;
	if (env_var)
		while (env_var[++i] && ++env_len)
			arg[(*arg_ref)++] = env_var[i];
	else if (++env_len)
		arg[(*arg_ref)++] = ' ';
	(*line_ref)--;
	if (env_name[0] == '?' && !env_name[1])
		free(env_var);
	free(env_name);
	return (env_len - line_len);
}

static int	is_spc(char *ln, int ln_ref)
{
	if (ln[ln_ref] == '$' && ln[ln_ref + 1]
		&& (ft_isalnum(ln[ln_ref + 1]) || ln[ln_ref + 1] == '?'))
		return (1);
	return (0);
}

static char	*ft_parse_str_env(char *ln, int init_arg, int len, int *parsed_le)
{
	char	*arg_line;
	int		ln_ref;
	int		arg_rf;
	int		should_pars;

	ln_ref = -1;
	arg_rf = 0;
	should_pars = 1;
	arg_line = ft_calloc(sizeof(char), 50000);
	*parsed_le = len;
	while (ln[++ln_ref])
	{
		if (ln_ref >= init_arg && ln_ref < init_arg + len)
		{
			if (ln[ln_ref] == '\'')
				should_pars *= -1;
			if (is_spc(ln, ln_ref) && (should_pars > 0 || ln[init_arg] == '\"'))
				*parsed_le += ft_includ_env(&ln_ref, ln, &arg_rf, arg_line);
			else
				arg_line[arg_rf++] = ln[ln_ref];
		}
		else
			arg_line[arg_rf++] = ln[ln_ref];
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
	else if (line[init_arg + len - 1] == '|')
		final_line = ft_substr(arg_line, init_arg, len - 1);
	else if (line[init_arg + len - 1] == '<' || line[init_arg + len - 1] == '>')
	{
		if (line[init_arg + len - 2] == '<' || line[init_arg + len - 2] == '>')
			final_line = ft_substr(arg_line, init_arg, len - 2);
		else
			final_line = ft_substr(arg_line, init_arg, len - 1);
	}
	else
		final_line = ft_substr(arg_line, init_arg, parsed_len);
	free(arg_line);
	return (final_line);
}
