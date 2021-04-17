/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:53:58 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/07 01:37:44 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	loop;

	loop = 0;
	while ((loop < n) && (src[loop] != '\0'))
	{
		dest[loop] = src[loop];
		loop++;
	}
	while (loop < n)
	{
		dest[loop] = '\0';
		loop++;
	}
	return (dest);
}
