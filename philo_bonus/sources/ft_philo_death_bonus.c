/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_death_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:31:54 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/09 00:31:55 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

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
		ft_delay(5, philo->shared_data);
	}
	return (0);
}
