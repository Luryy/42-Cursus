/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:50:11 by elima-me          #+#    #+#             */
/*   Updated: 2021/12/15 19:50:13 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_cd(char **path)
{
	int		path_len;

	path_len = 0;
	while (path[path_len])
		path_len++;
	if (path_len > 1)
		return (ft_putstr_fd("too many arguments\n", 1));
	if (chdir(path[0]) == -1)
		return (ft_putstr_fd("No such file or directory\n", 1));
}
