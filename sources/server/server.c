/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 08:36:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/05 18:51:38 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	ft_sigaction(int sig, siginfo_t *siginfo, void *context)
{
	static unsigned int	count;
	static unsigned int	letter;

	(void)context;
	if (count > 7)
	{
		count = 0;
		letter = 0;
	}
	if (sig == SIGUSR2)
	{
		letter += 1 << count;
	}
	count++;
	if (count == 8)
	{
		if (letter == 0)
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			write(1, &letter, 1);
	}
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_sigaction;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_printf("[SERVER] > listening on pid %d\n", getpid());
	while (1)
	{
		pause();
	}
}
