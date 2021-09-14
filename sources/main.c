/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:25:24 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/14 18:50:45 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <fdf.h>
# include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
} t_vars;

typedef struct s_offset
{
	int y;
	int x;
} t_offset;

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void draw_line(t_data *data, int size, t_offset *offset, int axios)
{
	int i;

	i = -1;
	while (++i < size)
	{
		if (axios)
			my_mlx_pixel_put(data, offset->y + i, offset->x, 0x00FF0000);
		else
			my_mlx_pixel_put(data, offset->y, offset->x + i, 0x00FF0000);
	}
}

void draw_square(t_data *data, int size, t_offset *offset)
{
	draw_line(data, size, offset, 1);
	draw_line(data, size, offset, 0);
	offset->x = offset->x + size;
	draw_line(data, size, offset, 1);
	offset->x = offset->x - size;
	offset->y = offset->y + size;
	draw_line(data, size, offset, 0);
}

int key_hook(int keycode, t_vars *vars)
{
	t_data img;
	t_offset offset;
	printf("%d\n", keycode);
	if (keycode == 65362)
	{

		img.img = mlx_new_image(vars->mlx, 1080, 540);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									 &img.endian);

		offset.x = 300;
		offset.y = 300;
		draw_square(&img, 50, &offset);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
	}
}

int closeWin(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		mlx_destroy_window(vars->mlx, vars->win);
}

int render_next_frame(t_vars *vars){
	t_data img;
	static t_offset offset;

	img.img = mlx_new_image(vars->mlx, 1080, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);

	offset.x = 1 + offset.x;
	offset.y = 1 + offset.y;
	draw_square(&img, 50, &offset);
	mlx_put_image_to_window(vars->mlx, vars->win, img.img, 0, 0);
};

int test_gnl()
{
	int fd;
	int i;
	int j;
	char *line = 0;
	char *lineadress[66];

	j = 1;

	if (!(fd = open("maps/test_maps/10-2.fdf", O_RDONLY)))
	{
		printf("\nError in open\n");
		return (0);
	}
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("|%s\n", line);
		lineadress[j - 1] = line;
		j++;
	}
	printf("|%s\n", line);
	free(line);
	close(fd);
}

int main(void)
{
	void *mlx;
	void *mlx_win;
	t_data img;
	t_offset offset;
	t_vars vars;

	test_gnl();
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1080, 540, "Hello world!");

	vars.mlx = mlx;
	vars.win = mlx_win;

	img.img = mlx_new_image(mlx, 1080, 540);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	offset.x = 100;
	offset.y = 100;
	draw_square(&img, 50, &offset);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_hook(vars.win, 2, 1L << 0, closeWin, &vars);

	mlx_loop_hook(mlx, render_next_frame, &vars);
	mlx_loop(mlx);
	return (1);
}
