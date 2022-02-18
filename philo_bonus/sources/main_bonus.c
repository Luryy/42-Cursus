/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:32:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/10 00:47:48 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	ft_philos_data_fork(t_data *data)
{
	int	i;

	i = -1;
	data->last_meal = data->start_timestamp;
	data->num_meals = 0;
	while (++i < data->philosophers)
	{
		usleep (10);
		data->pid = fork();
		if (data->pid)
			data->pid_arr[i] = data->pid;
		if (data->pid < 0)
			return (0);
		if (!data->pid)
		{
			data->id = i + 1;
			break ;
		}
	}
	return (1);
}

static void	ft_exiter(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philosophers)
		kill(data->pid_arr[i], SIGTERM);
	free(data->pid_arr);
	sem_close(data->forks);
	sem_close(data->m_food);
	sem_close(data->m_death);
	sem_close(data->m_print);
	sem_close(data->m_status);
	sem_close(data->philos_full);
}

static void	ft_await(t_data *data)
{
	int	wstatus;

	while (waitpid(0, &wstatus, 0) > 0)
	{
		ft_exiter(data);
		break ;
		usleep(10);
	}
}

void	*ft_monitor_eat(void *params)
{
	t_data	*data;
	int		i;

	data = params;
	i = 0;
	while (i++ < data->philosophers)
		sem_wait(data->philos_full);
	ft_exiter(data);
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_data		data;
	pthread_t	thread;

	if (!ft_init_args(argc, argv, &data))
		return (1);
	if (!ft_philos_data_fork(&data))
		return (1);
	if (!data.pid)
		ft_philos(&data);
	else
	{
		if (data.meals_to_full)
		{
			pthread_create(&thread, NULL, ft_monitor_eat, &data);
			pthread_detach(thread);
		}
		ft_await(&data);
	}
	return (0);
}
