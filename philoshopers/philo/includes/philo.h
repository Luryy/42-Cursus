/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:48:34 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/02/14 20:17:56 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef unsigned long	t_uint64;

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
	t_uint64		start_timestamp;
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
	t_uint64		last_meal;
	pthread_t		thread_ph;
	pthread_mutex_t	left_fork;
	pthread_mutex_t	*right_fork;
	t_shared_data	*shared_data;
}	t_philosophers;

t_philosophers	*ft_init_args(int argc, char **argv, t_shared_data *data);

int				ft_atoi_positive(const char *nptr);
int				ft_isdigit(int c);
t_uint64		ft_gettime(void);
void			ft_log(t_philosophers *philo, int status);
void			ft_delay(t_uint64 time, t_shared_data *data);

int				ft_philos(t_philosophers *philos);

int				ft_get_status(t_shared_data *data);
void			*ft_philo_death(void *params);

#endif
