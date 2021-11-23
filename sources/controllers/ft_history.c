/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 19:10:29 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/23 20:12:29 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_load_history(void)
{
	int		fd;
	char	*line;

	fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0777);
	while (get_next_line(fd, &line) > 0)
	{
		add_history(line);
		free(line);
	}
	close(fd);
}

void	ft_add_history(char *cmd)
{
	int		fd;

	if (!cmd[0])
		return ;
	fd = open(HISTORY_FILE, O_CREAT | O_RDWR | O_APPEND, 0777);
	ft_putstr_fd(cmd, fd);
	ft_putstr_fd("\n", fd);
	add_history(cmd);
	close(fd);
}
