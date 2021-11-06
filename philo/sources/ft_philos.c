/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:55:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/06 20:06:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*ft_runner(void *params)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)params;
	printf("%d\n", philo->id);
	return (0);
}

int	ft_philos(t_philosophers *philos)
{
	int	i;

	i = -1;
	while (++i < philos->shared_data->philosophers)
	{
		if (pthread_create(&philos[i].thread_ph, NULL, &ft_runner, &philos[i]))
		{
			printf("Error: Thread creation failed");
			return (0);
		}
	}
	i = -1;
	while (++i < philos->shared_data->philosophers)
	{
		if (pthread_join(philos[i].thread_ph, NULL))
		{
			printf("Error: Thread join failed\n");
			return (0);
		}
	}
	return (1);
}
