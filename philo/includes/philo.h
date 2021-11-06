/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:48:34 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/06 16:23:18 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# include <stdint.h>

enum e_application_status
{
	LIVE,
	DEAD,
	FULL,
};

typedef struct s_shared_data
{
	int				app_status;
	int				philosophers;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals_to_full;
	int				philos_full;
	uint64_t		start_timestamp;
	pthread_t		t_death;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_food;
	pthread_mutex_t	m_death;
	pthread_mutex_t	m_status;
}	t_shared_data;

typedef struct s_philosophers
{
	int				id;
	int				num_meals;
	uint64_t		last_meal;
	pthread_t		thread_ph;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_shared_data	*shared_data;
}	t_philosophers;

t_philosophers	*ft_init_args(int argc, char **argv, t_shared_data *data);

int				ft_atoi_positive(const char *nptr);
int				ft_isdigit(int c);
uint64_t		ft_gettime(void);

#endif
