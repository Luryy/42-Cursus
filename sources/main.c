/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:00:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 20:57:38 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_content	content;

	content.list_a = NULL;
	content.list_b = NULL;
	if (argc <= 1)
		return (0);
	ft_init_args(argc, argv, &content);
	ft_index(content.list_a);
	ft_clean(&content);
	return (1);
}
