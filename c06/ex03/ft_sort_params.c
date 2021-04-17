/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 00:11:38 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/14 00:31:04 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int		ft_strcmp(char *s1, char *s2)
{
	int n;

	n = 0;
	while (*s1 != '\0' || *s2 != '\0')
	{
		n = *s1 - *s2;
		if (n != 0)
			return (n);
		s1++;
		s2++;
	}
	return (n);
}

int		main(int argc, char *argv[])
{
	int		i;
	char	**swap;

	i = 0;
	swap = argv;
	while (++i < argc - 1)
	{
		if (ft_strcmp(argv[i], argv[i + 1]) > 0)
		{
			*swap = argv[i];
			argv[i] = argv[i + 1];
			argv[i + 1] = *swap;
			i = 0;
		}
	}
	i = 0;
	while (++i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
	}
	return (1);
}
