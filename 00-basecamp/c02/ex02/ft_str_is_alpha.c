/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 20:07:56 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/08 18:48:36 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str != 0)
	{
		if (!((97 <= *str && *str <= 122) ||
		(65 <= *str && *str <= 90)))
			return (0);
		str++;
	}
	return (1);
}
