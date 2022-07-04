/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 23:34:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/05 23:37:50 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int swap_division;
	int swap_rest;

	swap_division = a / b;
	swap_rest = a % b;
	*a = swap_division;
	*b = swap_rest;
}
