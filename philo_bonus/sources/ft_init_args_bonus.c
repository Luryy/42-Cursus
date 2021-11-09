/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:30:48 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/10 00:08:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

static int	ft_validate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi_positive(argv[i]) < 0)
			return (1);
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
	}
	return (0);
}

static void	ft_set_data(int argc, char **argv, t_data *data)
{
	data->philosophers = ft_atoi_positive(argv[1]);
	data->time_die = ft_atoi_positive(argv[2]);
	data->time_eat = ft_atoi_positive(argv[3]);
	data->time_sleep = ft_atoi_positive(argv[4]);
	data->meals_to_full = 0;
	data->philos_full = 0;
	data->app_status = LIVE;
	if (argc == 6)
		data->meals_to_full = ft_atoi_positive(argv[5]);
	data->start_timestamp = ft_gettime();
}

static int	ft_init_semaphore(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("m_food");
	sem_unlink("m_death");
	sem_unlink("m_print");
	sem_unlink("m_status");
	sem_unlink("philos_full");
	data->forks = sem_open(
			"forks", 100, S_IRWXU, (unsigned int)data->philosophers);
	data->m_food = sem_open("m_food", 100, S_IRWXU, 1);
	data->m_death = sem_open("m_death", 100, S_IRWXU, 1);
	data->m_print = sem_open("m_print", 100, S_IRWXU, 1);
	data->m_status = sem_open("m_status", 100, S_IRWXU, 1);
	data->philos_full = sem_open("philos_full", 100, S_IRWXU, 0);
	data->pid_arr = malloc(sizeof(*data->pid_arr) * data->philosophers);
	if (data->forks == SEM_FAILED
		|| data->m_food == SEM_FAILED
		|| data->m_death == SEM_FAILED
		|| data->m_print == SEM_FAILED
		|| data->m_status == SEM_FAILED
		|| data->philos_full == SEM_FAILED
		|| !data->pid_arr)
		return (1);
	return (0);
}

int	ft_init_args(int argc, char **argv, t_data *data)
{
	if (argc != 5 && argc != 6)
	{
		printf("Error: Invalid number of arguments\n");
		return (0);
	}
	if (ft_validate(argc, argv))
	{
		printf("Error: Invalid arguments type\n");
		return (0);
	}
	ft_set_data(argc, argv, data);
	if (ft_init_semaphore(data))
	{
		printf("Error: Semaphore failed\n");
		return (0);
	}
	return (1);
}
