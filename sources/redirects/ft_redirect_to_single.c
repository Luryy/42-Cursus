/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_to_single.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:49:10 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/11 21:33:30 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

void	ft_redirect_to_single(t_exec *exec_info)
{
	int		fd[2];
	int		pid;
	int		file;
	char	buffer;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		ft_execute_cmd(exec_info, 0);
	}
	else
	{
		close(fd[1]);
		file = open(exec_info[1].cmd, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		while (read(fd[0], &buffer, 1))
			write(file, &buffer, 1);
		close(file);
		close(fd[0]);
	}
	waitpid(pid, NULL, 0);
}

// pegar o que foi escrito antes do redirect 
// overwrite para o arquivo que foi direcionado 
// se nao existir vai criar o arquivo 
// se existir vai sobre escrever o que tem nele  