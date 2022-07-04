/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:22:09 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 18:40:11 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_fibonacci(int index)
{
	int fibo_before;
	int fibo_anti_before;

	if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	else if (index < 0)
		return (-1);
	fibo_before = ft_fibonacci(index - 1);
	fibo_anti_before = ft_fibonacci(index - 2);
	return (fibo_before + fibo_anti_before);
}
