/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/10 18:16:28 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/10 18:24:14 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*lst_actual;
	t_list	*lst_next;

	if (lst == NULL)
		return ;
	lst_actual = *lst;
	while (lst_actual->next != NULL)
	{
		lst_next = lst_actual->next;
		ft_lstdelone(lst_actual, del);
		lst_actual = lst_next;
	}
	lst = NULL;
}
