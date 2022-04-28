/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:13:46 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/04/27 21:54:27 by lyuri-go         ###   ########.fr       */
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
	int		user_x;
	int		user_y;
	int		user_view;
	int		quant_line;
	int		quant_max_col;
	char	**all_map;
}				t_map;

typedef struct s_texture
{
	char	*n;
	char	*w;
	char	*e;
	char	*s;
	char	*f;
	char	*c;
}				t_texture;

typedef struct s_img {
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_img;

typedef struct s_mlx {
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		view;
	t_img		map;
}				t_mlx;

typedef struct s_all
{
	t_mlx		*mlx_info;
	t_map		*map;
	t_texture	*texture;
}				t_all;

enum	e_directions {
	N = 1,
	W,
	E,
	S,
};

// MAP
int		find_map(t_all *all, int argc, char *argv);

// PARSER
void	parse_map(t_all *all, int fd1);
int		populate_map_var(t_map *map, int fd1);
int		validate_map_struct(t_map *map);

// UTILS
void	exiter(t_all *all, int exit_number);
void	ft_free(t_all *all);

// DRAW
void	border(t_img *img, int x, int y, int color);
void	render(t_mlx *mlx, t_all *all);
void	init_view(t_mlx *mlx, t_img *img);
void	init_map(t_mlx *mlx, t_img *img, t_all *all);
void	square(t_img *img, int x, int y, int color, int i, int j);

#endif
