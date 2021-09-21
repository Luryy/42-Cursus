/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:45:17 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/20 21:41:36 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h>

# include "../libs/libft/libft.h"
# include "../libs/minilibx/mlx.h"

typedef struct s_dot
{
	float		x;
	float		y;
	float		z;
	int			is_last;
}				t_dot;

typedef struct s_win {
	int			scale;
	int			z_scale;
	int			shift_x;
	int			shift_y;
	int			is_isometric;
	double		angle;
	int			win_x;
	int			win_y;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_win;

typedef struct s_var {
	t_dot		***dot;
	t_win		**winfo;
}				t_var;

# define KSPACE 32
# define KLESS 45
# define KMORE 61
# define KESC 65307
# define KLEFT 65361
# define KUP 65362
# define KRIGHT 65363
# define KDOWN 65364
# define K1 49
# define K2 50
# define K8 56
# define K9 57

# define X_WIN_SIZE 1500
# define Y_WIN_SIZE 600

# define C_WHITE 0xFFFFFF
# define C_RED 0xFF0000
# define C_LIGTH_RED 0xFF0F1c
# define C_GREEN 0x00FF00

# define INIT_ANGLE 0.523599
# define INIT_SCALE 20

t_dot			**read_map(char *file_name);
void			draw(t_dot **matrix, t_win *winfo);
void			set_param(t_dot *a, t_dot *b, t_win *winfo);
int				deal_key(int key, t_var *var);
void			isometric(t_dot *dot, double angle);
void			print_menu(t_win *param);
void			ft_error(char *msg);
void			move(int key, t_dot **matrix, t_win *winfo);

#endif
