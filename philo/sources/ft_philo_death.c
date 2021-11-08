/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_death.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:03:40 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/08 13:09:21 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

void	*ft_philo_death(void *params)
{
	t_philosophers	*philo;
	t_uint64		time;
	t_uint64		last_meat_time;

	philo = (t_philosophers *)params;
	while (philo->shared_data->app_status == LIVE)
	{
		pthread_mutex_lock(&philo->shared_data->m_death);
		time = ft_gettime();
		last_meat_time = time - philo->last_meal;
		pthread_mutex_unlock(&philo->shared_data->m_death);
		if (last_meat_time > (t_uint64)philo->shared_data->time_die)
		{
			pthread_mutex_lock(&philo->shared_data->m_status);
			ft_log(philo, 0);
			philo->shared_data->app_status = DEAD;
			break ;
		}
		ft_usleep(5);
	}
	return (NULL);
}
