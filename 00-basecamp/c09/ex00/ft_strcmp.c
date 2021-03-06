/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 02:14:10 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/17 02:15:05 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
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
