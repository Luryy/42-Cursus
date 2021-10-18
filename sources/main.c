/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:00:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/18 20:16:38 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_content	content;

	if (argc <= 1)
		return (0);
	ft_init_args(argc, argv, &content.list_a);
	return (1);
}
