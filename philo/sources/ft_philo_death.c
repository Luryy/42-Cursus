/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:03:40 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/02/14 20:51:24 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	ft_get_status(t_shared_data *data)
{
	int	status;

	pthread_mutex_lock(&data->m_status);
	status = data->app_status;
	pthread_mutex_unlock(&data->m_status);
	return (status);
}

void	*ft_philo_death(void *params)
{
	t_philosophers	*philo;
	t_uint64		time;
	t_uint64		last_meat_time;

	philo = (t_philosophers *)params;
	while (ft_get_status(philo->shared_data) == LIVE)
	{
		pthread_mutex_lock(&philo->shared_data->m_death);
		time = ft_gettime();
		pthread_mutex_lock(&philo->shared_data->m_food);
		last_meat_time = time - philo->last_meal;
		pthread_mutex_unlock(&philo->shared_data->m_food);
		pthread_mutex_unlock(&philo->shared_data->m_death);
		if (last_meat_time > (t_uint64)philo->shared_data->time_die)
		{
			ft_log(philo, 0);
			pthread_mutex_lock(&philo->shared_data->m_status);
			philo->shared_data->app_status = DEAD;
			pthread_mutex_unlock(&philo->shared_data->m_status);
			break ;
		}
		ft_delay(5, philo->shared_data);
	}
	return (0);
}
