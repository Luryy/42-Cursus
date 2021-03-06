/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:35:41 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/06 16:27:17 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

static int	ft_validate(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		if (ft_atoi_positive(argv[i]) <= 0)
			return (1);
		j = -1;
		while (argv[i][++j])
			if (!ft_isdigit(argv[i][j]))
				return (1);
	}
	return (0);
}

static void	ft_set_data(int argc, char **argv, t_shared_data *data)
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

static int	ft_init_mutex(t_shared_data *data)
{
	if (pthread_mutex_init(&data->m_print, NULL) \
	|| pthread_mutex_init(&data->m_death, NULL) \
	|| pthread_mutex_init(&data->m_food, NULL) \
	|| pthread_mutex_init(&data->m_status, NULL))
		return (1);
	return (0);
}

int	ft_philos_data(t_shared_data *data, t_philosophers *philos)
{
	int	i;

	i = -1;
	while (++i < data->philosophers)
	{
		philos[i].id = i + 1;
		philos[i].shared_data = data;
		philos[i].last_meal = data->start_timestamp;
		philos[i].num_meals = 0;
		if (pthread_mutex_init(&philos[i].left_fork, NULL))
		{
			printf("Error: Mutex failed\n");
			return (1);
		}
		if (i == data->philosophers - 1)
			philos[i].right_fork = &philos[0].left_fork;
		else
			philos[i].right_fork = &philos[i + 1].left_fork;
	}
	return (0);
}

t_philosophers	*ft_init_args(int argc, char **argv, t_shared_data *data)
{
	t_philosophers	*philos;

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
	if (ft_init_mutex(data))
	{
		printf("Error: Mutex failed\n");
		return (0);
	}
	philos = malloc(sizeof(t_philosophers) * data->philosophers);
	if (ft_philos_data(data, philos))
	{
		free(philos);
		return (0);
	}
	return (philos);
}
