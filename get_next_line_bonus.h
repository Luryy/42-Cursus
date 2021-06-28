/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:24:02 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/18 18:24:03 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define MAX_FILE_DESCRIPTOR FOPEN_MAX

size_t	ft_strlen(const char *s);
char	*ft_strdup(char *source);
int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
void	*ft_memmove(void *dest, const void *src, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
