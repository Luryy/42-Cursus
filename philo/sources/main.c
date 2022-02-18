/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 14:47:22 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/06 20:05:07 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philo.h>

int	main(int argc, char **argv)
{
	t_shared_data	data;
	t_philosophers	*philos;

	philos = ft_init_args(argc, argv, &data);
	if (!philos)
		return (1);
	ft_philos(philos);
	free(philos);
	return (0);
}
