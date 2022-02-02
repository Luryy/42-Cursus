/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_envs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:38:40 by elima-me          #+#    #+#             */
/*   Updated: 2022/01/27 17:43:45 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

static int	count_list(void)
{
	t_env	*envs;
	int		size;

	envs = mini_s()->envs;
	size = 0;
	while (envs)
	{
		size++;
		envs = envs->next;
	}
	return (size);
}

static char	*ft_join(char *str1, char c, char *str2)
{
	char	*joined;
	int		i;
	int		j;
	int		size;

	i = -1;
	j = -1;
	size = ft_strlen(str1) + ft_strlen(str2) + 2;
	joined = (char *)ft_calloc(size, sizeof(char));
	while (str1[++i])
		joined[i] = str1[i];
	joined[i] = c;
	i++;
	while (str2[++j])
	{
		joined[i] = str2[j];
		i++;
	}
	return (joined);
}

char	**ft_join_envs(void)
{
	int		size;
	char	**envs_arr;
	t_env	*envs;
	int		i;

	envs = mini_s()->envs;
	i = 0;
	size = count_list();
	envs_arr = (char **)ft_calloc(sizeof(char *), size + 1);
	while (i < size && (envs))
	{
		envs_arr[i] = ft_join(envs->key, '=', envs->value);
		envs = envs->next;
		i++;
	}
	return (envs_arr);
}
