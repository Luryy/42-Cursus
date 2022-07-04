/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:48:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/13 02:11:46 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned	int i;
	int				r;

	r = 0;
	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (i < n))
	{
		r = s1[i] - s2[i];
		if (r != 0)
			return (r);
		i++;
	}
	return (r);
}