/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 14:40:37 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/05 14:54:57 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
