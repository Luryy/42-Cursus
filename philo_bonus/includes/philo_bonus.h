/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:28:09 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/09 22:55:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H

# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <semaphore.h>
# include <sys/stat.h>
# include <signal.h>
# include <sys/wait.h>

typedef unsigned long	t_uint64;

enum e_application_status
{
	LIVE,
	DEAD,
	FULL,
};

typedef struct s_data
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
	sem_t			*m_print;
	sem_t			*m_food;
	sem_t			*m_death;
	sem_t			*m_status;
	int				id;
	int				num_meals;
	t_uint64		last_meal;
	pthread_t		thread_ph;
	sem_t			*forks;
	pid_t			*pid_arr;
	pid_t			pid;
}	t_data;

int				ft_init_args(int argc, char **argv, t_data *data);

int				ft_atoi_positive(const char *nptr);
int				ft_isdigit(int c);
t_uint64		ft_gettime(void);
void			ft_log(t_data *data, int status);
void			ft_delay(t_uint64 time, t_data *data);

int				ft_philos(t_data *data);

#endif
