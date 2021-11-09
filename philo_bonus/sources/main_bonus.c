/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:32:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/09 23:35:14 by lyuri-go         ###   ########.fr       */
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
	int	wstatus;

	while (waitpid(0, &wstatus, 0) > 0)
	{
		i = -1;
		while (++i < data->philosophers)
			kill(data->pid_arr[i], SIGTERM);
		break ;
		usleep(10);
	}
	free(data->pid_arr);
	sem_unlink("forks");
	sem_unlink("m_food");
	sem_unlink("m_death");
	sem_unlink("m_print");
	sem_unlink("m_status");
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (!ft_init_args(argc, argv, &data))
		return (1);
	if (!ft_philos_data_fork(&data))
		return (1);
	if (!data.pid)
		ft_philos(&data);
	else
		ft_exiter(&data);
	return (0);
}
