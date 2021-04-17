/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 01:17:14 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/09 02:18:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned	int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int dest_length;
	unsigned int src_length;
	unsigned int loop;

	dest_length = 0;
	src_length = 0;
	loop = 0;
	while ((dest[dest_length] != '\0'))
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (size <= dest_length)
		return (size + src_length);
	while (loop < (size - dest_length - 1))
	{
		dest[dest_length + loop] = src[loop];
		loop++;
	}
	dest[dest_length + loop] = '\0';
	return (dest_length + src_length);
}
