/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 07:57:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/18 19:00:04 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_info {
	int				value;
}	t_info;

typedef struct s_content {
	struct s_list	*list_a;
	struct s_list	*list_b;
}	t_content;

void	ft_init_args(int argc, char **argv, t_list **list);

#endif
