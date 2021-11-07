/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:55:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/07 18:35:49 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	ft_get_forks(t_philosophers *philo)
{
	if (!(philo->id % 2))
	{
		pthread_mutex_lock(&philo->left_fork);
		ft_log(philo, 4);
		pthread_mutex_lock(philo->right_fork);
		ft_log(philo, 4);
	}
	else
	{
		pthread_mutex_lock(philo->right_fork);
		ft_log(philo, 4);
		pthread_mutex_lock(&philo->left_fork);
		ft_log(philo, 4);
	}
}

static void	ft_eat(t_philosophers *ph)
{
	if (ph->shared_data->philosophers == 1)
	{
		usleep(1);
		ft_eat(ph);
		return ;
	}
	ft_get_forks(ph);
	pthread_mutex_lock(&ph->shared_data->m_food);
	ph->last_meal = ft_gettime();
	pthread_mutex_unlock(&ph->shared_data->m_food);
	ft_log(ph, 1);
	ft_delay(ph->shared_data->time_eat, ph->shared_data);
	pthread_mutex_unlock(ph->right_fork);
	pthread_mutex_unlock(&ph->left_fork);
}

void	*ft_runner(void *params)
{
	t_philosophers	*philo;

	philo = (t_philosophers *)params;
	while (philo->shared_data->app_status == LIVE)
	{
		ft_eat(philo);
		ft_log(philo, 2);
		ft_delay(philo->shared_data->time_sleep, philo->shared_data);
		ft_log(philo, 3);
	}
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
			printf("Error: Thread creation failed\n");
			return (0);
		}
		ft_delay(1, philos->shared_data);
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
