/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 07:57:18 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 10:26:15 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <stdio.h>

# define MAX_INT 2147483647
# define MIN_INT -2147483648

typedef struct s_info {
	int				value;
	int				index;
	int				tag_keep;
	struct s_list	*next_ordered;
}	t_info;

typedef struct s_content {
	struct s_list	*list_a;
	struct s_list	*list_b;
	struct s_list	*list_a_ref;
	int				biggest_sequence;
	int				length;
	int				total_nb;
	int				groups;
	int				groups_len;
	int				is_string_params;
}	t_content;

void	ft_init_args(int argc, char **argv, t_content *content);

void	ft_error(t_content *content);
void	ft_clean(t_content *content);
void	ft_validation_error(t_content *conten, t_info *inf, char **argv, int i);

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

void	ft_sort(t_content *content);

void	ft_set_content_info(t_content *content);
int		ft_distance_to_index(t_list *a, int tag);
int		ft_is_sequence(t_list *list_a);
t_list	*ft_get_closest_group(t_list *list, int actual_group, int group_total);
void	ft_set_rotation(t_content *cont, int max_dis, int *a_rot, int *b_rot);

int		ft_max(int nb_1, int nb_2);
int		ft_min(int nb_1, int nb_2);
int		ft_abs(int nb);
int		ft_atoi_safe(t_content *content, char **arv, t_info *inf, int i);

int		ft_biggest_seq_tag(t_list *start, int tag);

void	ft_rotate(t_content *content, int a_rot, int b_rot);

#endif
