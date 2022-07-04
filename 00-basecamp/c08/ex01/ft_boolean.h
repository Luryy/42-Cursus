/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 11:47:00 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/04/16 13:49:35 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H

# include <unistd.h>

# define EVEN(nbr)	(nbr % 2 == 0)
# define SUCCESS	1
# define ODD_MSG	"I have an odd number of arguments.\n"
# define EVEN_MSG	"I have an even number of arguments.\n"
# define TRUE		1
# define FALSE		0

typedef int	t_bool;

#endif
