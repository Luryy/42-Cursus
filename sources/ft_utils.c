/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 10:23:31 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 11:33:54 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_max(int nb_1, int nb_2)
{
	if (nb_1 > nb_2)
		return (nb_1);
	return (nb_2);
}

int	ft_min(int nb_1, int nb_2)
{
	if (nb_1 < nb_2)
		return (nb_1);
	return (nb_2);
}

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

int	ft_atoi_safe(t_content *content, char **argv, t_info *inf, int i)
{
	int					signal;
	unsigned long int	number;
	const char			*nptr;

	number = 0;
	signal = 1;
	nptr = argv[i];
	while (*nptr == ' ')
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			signal *= -1;
	if (!ft_isdigit(*nptr))
		ft_validation_error(content, inf, argv, i);
	while (*nptr >= 48 && *nptr <= 57)
	{
		number = (*nptr - 48) + (number * 10);
		nptr++;
	}
	if ((number > MAX_INT && signal > 0) || (signal < 0 && number > -MIN_INT)
		|| (*nptr && *nptr != ' '))
		ft_validation_error(content, inf, argv, i);
	return (signal * number);
}
