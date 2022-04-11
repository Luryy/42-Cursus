/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/11 20:14:44 by lyuri-go         ###   ########.fr       */
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
	int	qt_line;
	int	qt_col;
	int	qt_arq;
}				t_map;

typedef struct s_all
{
	int		whatever;
	t_map	*map;
}				t_all;

int	check_map(t_all *all, int argc, char **argv);
int	cont_col(t_map *map, char *argv);
int	cont_line(t_map *map, int fd1);
int	map_struct(t_map *map, char *argv);

#endif
