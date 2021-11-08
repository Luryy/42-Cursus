/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 15:55:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/08 13:21:10 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static void	ft_full_eat(t_philosophers *philo)
{
	if (philo->shared_data->app_status == LIVE)
	{
		pthread_mutex_lock(&philo->shared_data->m_food);
		philo->num_meals++;
		if (philo->num_meals == philo->shared_data->meals_to_full)
			philo->shared_data->philos_full++;
		pthread_mutex_unlock(&philo->shared_data->m_food);
		if (philo->shared_data->philos_full == philo->shared_data->philosophers)
		{
			pthread_mutex_lock(&philo->shared_data->m_status);
			philo->shared_data->app_status = FULL;
			return ;
		}
	}
}

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

static void	ft_eat(t_philosophers *philo)
{
	if (philo->shared_data->philosophers == 1)
	{
		usleep(1);
		ft_eat(philo);
		return ;
	}
	ft_get_forks(philo);
	pthread_mutex_lock(&philo->shared_data->m_food);
	philo->last_meal = ft_gettime();
	pthread_mutex_unlock(&philo->shared_data->m_food);
	ft_log(philo, 1);
	ft_delay(philo->shared_data->time_eat, philo->shared_data);
	ft_full_eat(philo);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(&philo->left_fork);
}

void	*ft_runner(void *params)
{
	t_philosophers	*philo;
	pthread_t		t_death;

	philo = (t_philosophers *)params;
	if (pthread_create(&t_death, NULL, &ft_philo_death, philo))
	{
		printf("Error: Thread creation failed\n");
		return (0);
	}
	if (pthread_detach(t_death))
	{
		printf("Error: Thread detach failed\n");
		return (0);
	}
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
