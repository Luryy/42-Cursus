/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:30:36 by lyuri-go          #+#    #+#             */
/*   Updated: 2021/12/01 18:34:50 by elima-me         ###   ########.fr       */
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

enum e_cmd_next_type {
	LAST,
	PIPE,
	REDIRECT_TO_SINGLE,
	REDIRECT_TO_DOUBLE,
	REDIRECT_FROM_SINGLE,
	REDIRECT_FROM_DOUBLE,
};

typedef struct s_exec {
	char	**args;
	char	*cmd;
	int		next_type;
}	t_exec;

typedef struct s_mini {
	char	**envs;
	int		last_exec_code;
}	t_mini;

// CONTROLLERS
void	ft_execute(char *line);
void	ft_signals(void);
void	ft_load_history(void);
void	ft_add_history(char *in);

// CMDS
void	ft_echo(char **argv);
void	ft_pwd(void);
void	ft_exit(t_exec *exec);

// UTILS
char	*ft_get_env(char *env);
t_mini	*mini_s(void);

//PARSERS
void	ft_parser(char *line, t_exec *exec_info);
void	ft_free_parser(t_exec *exec);

#endif
