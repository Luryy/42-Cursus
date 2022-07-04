/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:13:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/09 00:46:07 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_ini;
	unsigned int	i;

	dest_ini = dest;
	i = 0;
	while (*dest != '\0')
		dest++;
	while (src[i] != '\0' && i < nb)
	{
		*dest = src[i];
		dest++;
		i++;
	}
	*dest = '\0';
	return (dest_ini);
}
