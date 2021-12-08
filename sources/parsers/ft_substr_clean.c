/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_clean.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 21:30:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/08 21:59:58 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

char	*ft_substr_clean(char *line, int init_arg, int len)
{
	if (line[init_arg] == '|')
		return ('\0');
	else if (line[init_arg] == '<' || line[init_arg] == '>')
		return ('\0');
	else if (line[init_arg] == '\"' || line[init_arg] == '\'')
		return (ft_substr(line, init_arg + 1, len - 2));
	return (ft_substr(line, init_arg, len));
}
