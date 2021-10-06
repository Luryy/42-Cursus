/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:36:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/06 10:12:23 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	handle_client(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Finished signals successfully\n");
		exit(0);
	}
}

static void	ft_kill(int pid, int signal)
{
	kill(pid, signal);
	usleep(1100);
}

static void	send_char(int pid, unsigned char c)
{
	int	count;

	count = -1;
	while (++count < 8)
	{
		if (c % 2 == 0)
			ft_kill(pid, SIGUSR1);
		else
			ft_kill(pid, SIGUSR2);
		c /= 2;
	}
}

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc != 3)
	{
		ft_printf("Wrong input. Should be SERVER PID + MESSAGE\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_char(server_pid, *argv[2]++);
	signal(SIGUSR1, handle_client);
	send_char(server_pid, '\0');
	return (0);
}
