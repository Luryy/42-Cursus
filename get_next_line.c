/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 08:29:09 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/06/24 08:55:19 by lyuri-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_join_and_free(char *to_free, char *to_join)
{
	int		len1;
	int		len2;
	int		i;
	char	*dst;

	if (!to_free)
		return (ft_strdup(to_join));
	if (!to_join)
		return (NULL);
	len1 = ft_strlen(to_free);
	len2 = ft_strlen(to_join);
	dst = (char *) malloc((len1 + len2 + 1) * sizeof(char));
	if (!dst)
		return (NULL);
	i = -1;
	while (to_free[++i])
		dst[i] = to_free[i];
	free(to_free);
	to_free = NULL;
	i = -1;
	while (to_join[++i])
		dst[len1 + i] = to_join[i];
	dst[len1 + i] = '\0';
	return (dst);
}

int	get_line(char **str, char **line, int i)
{
	int		len;

	*line = ft_substr(*str, 0, i);
	i++;
	len = ft_strlen(*str + i) + 1;
	ft_memmove(*str, *str + i, len);
	if (*str && *str[0] == '\0')
	{
		free(*str);
		*str = NULL;
	}
	return (1);
}

void	final_verify(char **str, char **line)
{
	if (*str)
	{
		*line = ft_strdup(*str);
		free(*str);
		*str = NULL;
		return ;
	}
	*line = ft_strdup("");
}

int	get_next_line(int fd, char **line)
{
	static char		*str;
	static char		read_buffer[BUFFER_SIZE + 1];
	int				nr_bytes;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || fd > MAX_FILE_DESCRIPTOR)
		return (-1);
	if (str && ft_strchr(str, '\n'))
		return (get_line(&str, line, ft_strchr(str, '\n') - str));
	nr_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (nr_bytes > 0)
	{
		read_buffer[nr_bytes] = '\0';
		str = ft_join_and_free(str, read_buffer);
		if (ft_strchr(str, '\n'))
			return (get_line(&str, line, ft_strchr(str, '\n') - str));
		nr_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	final_verify(&str, line);
	return (nr_bytes);
}
