/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:32:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/09 22:49:30 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static void	ft_full_eat(t_data *data)
{
	if (data->app_status == LIVE)
	{
		sem_wait(data->m_food);
		data->num_meals++;
		if (data->num_meals == data->meals_to_full)
			data->philos_full++;
		sem_post(data->m_food);
		if (data->philos_full == data->philosophers)
		{
			sem_wait(data->m_status);
			data->app_status = FULL;
			return ;
		}
	}
}

static void	ft_get_forks(t_data *data)
{
	sem_wait(data->forks);
	ft_log(data, 4);
	sem_wait(data->forks);
	ft_log(data, 4);
}

static void	ft_eat(t_data *data)
{
	if (data->philosophers == 1)
	{
		usleep(1);
		ft_eat(data);
		return ;
	}
	ft_get_forks(data);
	sem_wait(data->m_food);
	data->last_meal = ft_gettime();
	sem_post(data->m_food);
	ft_log(data, 1);
	ft_delay(data->time_eat, data);
	ft_full_eat(data);
	sem_post(data->forks);
	sem_post(data->forks);
}

static void	*ft_philo_death(void *params)
{
	t_data		*data;
	t_uint64	time;
	t_uint64	last_meat_time;

	data = (t_data *)params;
	while (data->app_status == LIVE)
	{
		sem_wait(data->m_death);
		time = ft_gettime();
		last_meat_time = time - data->last_meal;
		sem_post(data->m_death);
		if (last_meat_time > (t_uint64)data->time_die)
		{
			sem_wait(data->m_status);
			ft_log(data, 0);
			data->app_status = DEAD;
			exit (0);
		}
		ft_delay(5, data);
	}
	return (0);
}

int	ft_philos(t_data *data)
{
	pthread_t	t_death;

	if (pthread_create(&t_death, NULL, &ft_philo_death, data))
	{
		printf("Error: Thread creation failed\n");
		return (0);
	}
	if (pthread_detach(t_death))
	{
		printf("Error: Thread detach failed\n");
		return (0);
	}
	while (data->app_status == LIVE)
	{
		ft_eat(data);
		ft_log(data, 2);
		ft_delay(data->time_sleep, data);
		ft_log(data, 3);
	}
	return (1);
}
