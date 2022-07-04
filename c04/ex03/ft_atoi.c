/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 01:21:06 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 14:36:25 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int signal;
	int number;

	number = 0;
	signal = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t'
	|| *str == '\v' || *str == '\f' || *str == '\r')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		number = (*str - 48) + (number * 10);
		str++;
	}
	return (signal * number);
}
