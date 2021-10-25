/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 17:58:42 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/10/25 18:31:03 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_operations(char *operation, t_content *content)
{
	if (!ft_strncmp(operation, "ra", 2))
		ft_ra(content);
	else if (!ft_strncmp(operation, "rb", 2))
		ft_rb(content);
	else if (!ft_strncmp(operation, "rr", 2))
		ft_rr(content);
	else if (!ft_strncmp(operation, "rra", 2))
		ft_rra(content);
	else if (!ft_strncmp(operation, "rrb", 2))
		ft_rrb(content);
	else if (!ft_strncmp(operation, "rrr", 2))
		ft_rrr(content);
	else if (!ft_strncmp(operation, "sa", 2))
		ft_sa(content);
	else if (!ft_strncmp(operation, "sb", 2))
		ft_sb(content);
	else if (!ft_strncmp(operation, "ss", 2))
		ft_ss(content);
	else if (!ft_strncmp(operation, "pa", 2))
		ft_pa(content);
	else if (!ft_strncmp(operation, "pb", 2))
		ft_pb(content);
	else
		return (0);
	return (1);
}

static void	ft_listen(t_content *content)
{
	char	buff[4];
	int		ite;
	int		before_ite;

	ite = 0;
	while (ite < 4)
	{
		before_ite = ite;
		ite += read(0, buff + ite, 1);
		if (before_ite == ite)
			break ;
		if (buff[before_ite] == '\n')
		{
			buff[before_ite] = 0;
			if (!ft_operations(buff, content))
				ft_error(content);
			ite = 0;
		}
	}
	if (ite == 4)
		ft_error(content);
}

int	main(int argc, char **argv)
{
	t_content	content;

	content.list_a = NULL;
	content.list_b = NULL;
	if (argc <= 1)
		return (0);
	ft_init_args(argc, argv, &content);
	ft_listen(&content);
	if (ft_is_sequence(content.list_a) && !content.list_b)
		ft_putstr_fd("OK", 1);
	else
		ft_putstr_fd("KO", 1);
	ft_clean(&content);
	return (0);
}
