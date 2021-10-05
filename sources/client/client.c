/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:36:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/05 18:52:55 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	handle_client(int sig)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Finished signals successfully\n");
		exit(0);
	}
}

void	send_char(int pid, unsigned char c)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		if (c % 2 == 0 || c == 0)
		{
			kill(pid, SIGUSR1);
			usleep(1100);
		}
		else
		{
			kill(pid, SIGUSR2);
			usleep(1100);
		}
		c /= 2;
		count++;
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
