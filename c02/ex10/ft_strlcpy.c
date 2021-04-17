/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 01:15:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 21:23:38 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	length;

	length = 0;
	while (src[length] != '\0')
	{
		if ((length < size - 1) && (size != 0))
			dest[length] = src[length];
		else if ((length == size - 1) && (size != 0))
			dest[length] = '\0';
		length++;
	}
	return (length);
}
