/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:32:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/12 19:11:41 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libs/libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	dot;
	int	star;
	int	zero;
	int	width;
	int	type;
}	t_flags;

int		ft_printf(const char *format, ...);
t_flags	ft_init_flags(void);
int		ft_parse(const char *str, int i, t_flags *flags, va_list args);
int		ft_handle_input(const char *str, va_list args);

#endif
