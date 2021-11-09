/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:33:05 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/09 01:05:13 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo_bonus.h>

int	ft_atoi_positive(const char *nptr)
{
	int					signal;
	unsigned long int	number;

	number = 0;
	signal = 1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			return (-1);
		nptr++;
	}
	while (*nptr >= 48 && *nptr <= 57)
	{
		number = (*nptr - 48) + (number * 10);
		nptr++;
	}
	if (number > 2147483647)
		return (-1);
	return (signal * number);
}

int	ft_isdigit(int c)
{
	if (!(48 <= c && c <= 57))
		return (0);
	return (1);
}

t_uint64	ft_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (0);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_log(t_data *data, int status)
{
	t_uint64	now;
	char		*status_str[5];

	status_str[0] = "\e[31mis DEAD\e[0m";
	status_str[1] = "\e[32mis eating\e[0m";
	status_str[2] = "\e[35mis sleeping\e[0m";
	status_str[3] = "\e[34mis thinking\e[0m";
	status_str[4] = "has taken a fork";
	sem_wait(data->m_print);
	now = ((ft_gettime() - data->start_timestamp));
	if (data->app_status == LIVE)
		printf("[\e[33m%lu\e[0m] %d %s\n", now, data->id, status_str[status]);
	sem_post(data->m_print);
}

void	ft_delay(t_uint64 time, t_data *data)
{
	t_uint64	timer;

	timer = ft_gettime();
	while ((ft_gettime() - timer) < time && data->app_status == LIVE)
		usleep(1);
}
