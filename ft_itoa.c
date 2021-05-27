/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 18:38:34 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/27 19:15:30 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	get_number_length(unsigned int nb)
{
	int nb_digit_numbers;

	nb_digit_numbers = 0;
	if (nb == 0)
	{
		nb_digit_numbers++;
	}
	while (nb != 0)
	{
		nb = nb / 10;
		nb_digit_numbers++;
	}
	return (nb_digit_numbers);
}

char	*ft_itoa(int n)
{
	unsigned	int	nbr;
	int				p_size;
	int				t_size;
	char			*n_char;

	if (n >= 0)
	{
		nbr = n;
		p_size = 0;
	}
	else
	{
		nbr = -n;
		p_size = 1;
	}
	t_size = get_number_length(nbr) + p_size;
	n_char = malloc(sizeof(char) * (t_size + 1));
	if (!n_char)
		return (NULL);
	if (p_size)
		n_char[0] = '-';
	while (nbr > 0)
	{
		n_char[--t_size] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (n_char[0] == '\0')
		n_char[0] = '0';
	return (n_char);
};
