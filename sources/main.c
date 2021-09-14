/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 08:25:24 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/09/14 19:28:37 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (!fd)
			return (0);
//
		int j = 1;
		char *line = 0;
		char *lineadress[66];
		int i;

		while ((i = get_next_line(fd, &line)) > 0)
		{
			printf("|%s\n", line);
			lineadress[j - 1] = line;
			j++;
		}
		printf("|%s\n", line);
		free(line);
		close(fd);
//
	}
	return (1);
}
