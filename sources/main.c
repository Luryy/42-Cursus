/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 08:00:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 10:26:55 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_content	content;
	int			already_sorted;

	content.list_a = NULL;
	content.list_b = NULL;
	if (argc <= 1)
		return (0);
	ft_init_args(argc, argv, &content);
	already_sorted = ft_is_sequence(content.list_a);
	if (already_sorted)
		return (0);
	ft_index(content.list_a);
	ft_set_content_info(&content);
	ft_sort(&content);
	ft_clean(&content);
	return (1);
}
