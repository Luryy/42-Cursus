/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/12 22:46:50 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>

typedef struct s_map
{
	int		qt_line;
	int		qt_col;
	int		qt_arq;
	char	**all_map;
	char	*path_map;
}				t_map;

typedef struct s_all
{
	int		whatever;
	t_map	*map;
}				t_all;

int	find_map(t_map *map,int argc, char *argv);
int	map_struct(t_map *map, int fd1);
int	populate_map_var(t_map *map, int fd1);

#endif
