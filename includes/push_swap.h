/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 07:57:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/20 20:32:01 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct s_info {
	int				value;
	int				index;
	struct s_list	*next_ordered;
}	t_info;

typedef struct s_content {
	struct s_list	*list_a;
	struct s_list	*list_b;
}	t_content;

void	ft_init_args(int argc, char **argv, t_content *content);

void	ft_error(t_content *content);
void	ft_clean(t_content *content);

void	ft_swap(t_list **stack);
void	ft_push_top(t_list **x1, t_list **x2);
void	ft_shift_up(t_list **x);
void	ft_shift_down(t_list **x);

void	ft_sa(t_content *content);
void	ft_sb(t_content *content);
void	ft_ss(t_content *content);
void	ft_pa(t_content *content);
void	ft_pb(t_content *content);
void	ft_ra(t_content *content);
void	ft_rb(t_content *content);
void	ft_rr(t_content *content);
void	ft_rra(t_content *content);
void	ft_rrb(t_content *content);
void	ft_rrr(t_content *content);

void	ft_index(t_list *list_init);

#endif
