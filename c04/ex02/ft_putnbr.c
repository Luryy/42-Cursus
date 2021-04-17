/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 22:24:12 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 01:19:58 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		pot(int base, int exponent)
{
	if (exponent == 0)
	{
		return (1);
	}
	else
	{
		return (base * pot(base, exponent - 1));
	}
}

int		get_number_lenght(unsigned int nb)
{
	int nb_to_use_to_count;
	int nb_digit_numbers;

	nb_to_use_to_count = nb;
	nb_digit_numbers = 0;
	if (nb_to_use_to_count == 0)
	{
		nb_digit_numbers++;
	}
	while (nb_to_use_to_count != 0)
	{
		nb_to_use_to_count = nb_to_use_to_count / 10;
		nb_digit_numbers++;
	}
	return (nb_digit_numbers);
}

int		*get_number_by_index(unsigned int nb, int index)
{
	int			current_potency;
	int			actual_number;
	static int	array_to_return[2];

	current_potency = pot(10, (index));
	actual_number = nb / current_potency;
	array_to_return[0] = actual_number;
	array_to_return[1] = current_potency;
	return (array_to_return);
}

void	ft_putnbr(int nb)
{
	int				nb_digit_numbers;
	int				number_to_print_in_ascii;
	int				actual_number;
	int				*array_return_info;
	unsigned	int	nb_usigned;

	if (nb < 0)
	{
		nb_usigned = 0 - nb;
		write(1, "-", 1);
	}
	else
		nb_usigned = nb;
	nb_digit_numbers = get_number_lenght(nb_usigned);
	nb = 0;
	while (++nb <= nb_digit_numbers)
	{
		array_return_info =
			get_number_by_index(nb_usigned, (nb_digit_numbers - nb));
		actual_number = array_return_info[0];
		nb_usigned = nb_usigned % array_return_info[1];
		number_to_print_in_ascii = actual_number + '0';
		write(1, &number_to_print_in_ascii, 1);
	}
}
