/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 09:22:57 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/20 08:30:32 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

char	*ft_str_to_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
	return (str);
}

static char	*ft_base(size_t nbr, int base, int count, char *str)
{
	while (nbr != 0)
	{
		if ((nbr % base) < 10)
			str[count - 1] = (nbr % base) + 48;
		else
			str[count - 1] = (nbr % base) + 55;
		nbr /= base;
		count--;
	}
	return (str);
}

char	*ft_utl_base(size_t nbr, int base)
{
	size_t	temp;
	int		count;
	char	*str;

	temp = nbr;
	count = 0;
	str = 0;
	if (nbr == 0)
		return (ft_strdup("0"));
	while (nbr != 0)
	{
		nbr /= base;
		count++;
	}
	str = malloc(count + 1);
	if (!str)
		return (0);
	str[count] = '\0';
	str = ft_base(temp, base, count, str);
	return (str);
}

char	*ft_u_itoa(unsigned int n)
{
	int				len;
	char			*str;
	unsigned int	num;

	len = 0;
	if (n == 0)
		len = 1;
	num = n;
	while (num)
	{
		num /= 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (str);
}
