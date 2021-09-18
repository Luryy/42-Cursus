/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 08:45:17 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/18 12:35:26 by lyuri-go         ###   ########.fr       */
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

	int			color;
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
}				t_dot;

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

t_dot			**read_map(char *file_name);
void			draw(t_dot **matrix);
void			set_param(t_dot *a, t_dot *b, t_dot *param);
int				deal_key(int key, t_dot **matrix);
void			isometric(t_dot *dot, double angle);
void			print_menu(t_dot param);
void			ft_error(char *msg);
void			move(int key, t_dot **matrix);

#endif
