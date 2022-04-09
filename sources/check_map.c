/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rarodrig < rarodrig@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 22:43:14 by rarodrig          #+#    #+#             */
/*   Updated: 2022/04/08 22:12:01 by rarodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int	check_extension(char *str, char *extension)
{
	int	len_str;
	int	len_ext;
	int	i;

	len_str = ft_strlen(str);
	len_ext = ft_strlen(extension);
	i = 0;
	while (len_ext > 0)
	{
		if (extension[--len_ext] == str[--len_str])
			i++;
		else
		{
			printf("Extensão do mapa inválido\n");
			return (0);
		}
	}
	return (1);
}


int check_map(t_all *all, int argc, char **argv)
{
	if(argc == 1)
	{
		printf("ERROR!! Input need some map .cub\n");
		return(0);
	}
	if(argc > 2)
		printf("Will be utilized the first file\n");
	if(!check_extension(argv[1], ".cub"))
		return (0);
	if (!map_struct(all->map, argv[1]))
		return(0);
	printf("map okay");
	return (1);
}