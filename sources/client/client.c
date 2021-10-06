/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:36:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/06 14:58:44 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

static void	handle_client(int sig, siginfo_t *siginfo, void *context)
{
	if (sig == SIGUSR1)
	{
		ft_printf("Finished signals successfully\n");
		exit(0);
	}
	if (sig == SIGUSR2)
	{
		(void)siginfo;
		(void)context;
	}
}

static void	ft_kill(int pid, int signal)
{
	kill(pid, signal);
	usleep(50);
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
	int					server_pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_printf("Wrong input. Should be SERVER PID + MESSAGE\n");
		return (1);
	}
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = handle_client;
	sigaction(SIGUSR1, &sig, 0);
	sigaction(SIGUSR2, &sig, 0);
	server_pid = ft_atoi(argv[1]);
	while (*argv[2])
		send_char(server_pid, *argv[2]++);
	send_char(server_pid, '\0');
	return (0);
}
