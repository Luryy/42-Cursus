/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 08:32:26 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/07/14 09:34:22 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libs/libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

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
t_flags	ft_minus_flag(t_flags flags);
t_flags	ft_width_flag(va_list args, t_flags flags);
t_flags	ft_digit_flag(char c, t_flags flags);
int		ft_dot_flag(const char *str, int start, va_list args, t_flags *flags);
int		ft_print_c(char c, t_flags flags);
int		ft_print_int(int i, t_flags flags);
int		ft_print_p(size_t num, t_flags flags);
int		ft_print_percent(t_flags flags);
int		ft_print_s(char *str, t_flags flags);
int		ft_print_u(unsigned int num, t_flags flags);
int		ft_print_width(int width, int minus, int zero);
int		ft_print_x(unsigned int num, int lowercase, t_flags flags);
int		ft_isconversion(int c);
int		ft_isflag(int c);
int		ft_handle(int c, t_flags flags, va_list args);

int		ft_putsp(char *str, int len);
char	*ft_str_to_lowercase(char *str);
char	*ft_utl_base(size_t nbr, int base);
char	*ft_u_itoa(unsigned int n);

#endif
