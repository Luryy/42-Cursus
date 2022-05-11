/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exiter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 20:11:39 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/05/10 20:46:10 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

void	ft_free(t_all *all)
{
	int	i;

	i = -1;
	if (all->map->all_map)
	{
		while (all->map->all_map[++i + 1])
			free(all->map->all_map[i]);
		free(all->map->all_map);
	}
}

int	exiter(t_all *all, int exit_number)
{
	ft_free(all);
	exit(exit_number);
	return (0);
}
