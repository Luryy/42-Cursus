/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 00:54:03 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/15 18:05:18 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_inside(char *principal, char *inside)
{
	int i;

	i = 0;
	while (inside[i] != '\0')
	{
		if (principal[i] != inside[i])
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (!(*to_find))
		return (str);
	while (*str != '\0')
	{
		if (*str == to_find[0])
		{
			if (ft_is_inside(str, to_find))
				return (str);
		}
		str++;
	}
	return (0);
}
