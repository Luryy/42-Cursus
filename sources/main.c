/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:11:59 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/25 22:40:20 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

static void	start_struct(t_all *all, t_map *map, t_texture *texture)
{
	all->map = map;
	all->texture = texture;
	all->whatever = 0;
	map->all_map = malloc(300 * sizeof(char *));
	all->map->user_x = -1;
	all->texture->n = NULL;
	all->texture->w = NULL;
	all->texture->e = NULL;
	all->texture->s = NULL;
	all->texture->f = NULL;
	all->texture->c = NULL;
}

int	main(int argc, char **argv)
{
	t_all			all;
	t_map			map;
	t_texture		texture;
	int				fd1;

	start_struct(&all, &map, &texture);
	fd1 = find_map(&all, argc, argv[1]);
	if (parse_map(&all, fd1))
		return (1);
	// int i = -1;
	// while (map.all_map[++i])
	// 	printf("%s\n", map.all_map[i]);
	ft_free(&all);
	return (0);
}
