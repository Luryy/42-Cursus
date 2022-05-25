/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_rgb_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 16:47:06 by rarodrig          #+#    #+#             */
/*   Updated: 2022/05/25 18:52:15 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	is_invalid_decimal(char *str)
{
	int	c;

	c = 0;
	while (str[c])
	{
		if (!ft_isdigit(str[c]))
			return (1);
		c++;
	}
	return (0);
}

static int	check_invalid_color(char *color)
{
	char	*aux;

	aux = ft_strtrim(color, " ");
	if (is_invalid_decimal(aux))
	{
		free(aux);
		return (1);
	}
	if (ft_strlen(aux) > 0 && ft_strlen(aux) <= 3)
	{
		free(aux);
		return (0);
	}
	free(aux);
	return (1);
}

int	convert_rgb_decimal(char **colors)
{
	int	r;
	int	g;
	int	b;

	if (check_invalid_color(colors[0]) || check_invalid_color(colors[1])
		|| check_invalid_color(colors[2]))
		return (-1);
	r = ft_atoi(colors[0]);
	g = ft_atoi(colors[1]);
	b = ft_atoi(colors[2]);
	free(colors[0]);
	free(colors[1]);
	free(colors[2]);
	if ((r > 255 || r < 0) || (g > 255 || g < 0) || (b > 255 || b < 0))
		return (-1);
	return (r * 65536 + g * 256 + b);
}

void	rgb_to_decimal(t_all *all)
{
	int		c;
	int		f;
	char	**colorc;
	char	**colorf;

	colorc = ft_split(all->texture->c, ',');
	colorf = ft_split(all->texture->f, ',');
	c = convert_rgb_decimal(colorc);
	f = convert_rgb_decimal(colorf);
	free(colorc);
	free(colorf);
	if (c == -1 || f == -1)
	{
		printf("Wrong Textures\n");
		exiter(all, -1);
	}
	all->texture->c_hexa = c;
	all->texture->f_hexa = f;
}
