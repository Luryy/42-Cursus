/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/27 16:44:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/05/29 17:25:02 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	*ft_count_times(char const *s, char c)
{
	int i;
	int is_sequence;
	int *c_times;

	i = -1;
	c_times = malloc(3 * sizeof(int));
	is_sequence = 1;
	while(s[++i] != 0)
	{
		if (s[i] == c)
		{
			c_times[0]++;
			if (!is_sequence)
				c_times[1]++;
			is_sequence = 1;
		}
		else
			is_sequence = 0;
	}
	return (c_times);
}

void	ft_count_word_length(int *j, const char *s, char c)
{
	int i;
	int n;

	i = -1;
	n = 0;
	j[n] = 0;
	while(s[++i] != 0)
	{
		if (s[i] == c)
		{
			n++;
			j[n] = -1;
		}
		j[n]++;
	}
	return;
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	int		*j;
	int		*c_times;
	int		k;
	int		offset;

	if (!s)
		return (NULL);
	c_times = ft_count_times(s, c);
	j = malloc((c_times[0] + 2) * sizeof(int));
	ft_count_word_length(j, s, c);
	split = malloc((c_times[1] + 2) * sizeof(char *));
	i = -1;
	k = 0;
	offset = 0;

	while (++i < c_times[0] + 2)
	{
		if (j[i] != 0)
			split[k++] = ft_substr(s, offset, (size_t)j[i]);
		offset += j[i] + 1;
	}
	split[k] = '\0';
	return (split);
};
