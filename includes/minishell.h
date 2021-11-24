/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:30:36 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/11/24 19:48:35 by elima-me         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include "../libs/libft/libft.h"
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <fcntl.h>

# define HISTORY_FILE "/.minishell_history"

typedef struct s_mini {
	char	**envs;
}	t_mini;

void	ft_execute(char *line);
void	ft_signals(void);
void	ft_load_history(void);
void	ft_add_history(char *in);

void	ft_echo(char **argv);
void	ft_pwd(void);

char	*ft_get_env(char *env);
t_mini	*mini_s(void);

#endif
