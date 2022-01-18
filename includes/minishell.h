/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyuri-go <lyuri-go@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:30:36 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/19 00:04:26 by lyuri-go         ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/wait.h>

# define HISTORY_FILE "/.minishell_history"

typedef struct s_env {
	char			*key;
	char			*value;
	struct s_env	*next;
	int				visible;
}	t_env;

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
	t_env	*envs;
	int		last_exec_code;
}	t_mini;

// CONTROLLERS
void	ft_execute(char *line);
void	ft_signals(void);
void	ft_load_history(void);
void	ft_add_history(char *in);
void	ft_free(t_exec *exec);

// CMDS
void	ft_echo(char **argv);
void	ft_pwd(void);
void	ft_exit(t_exec *exec);
void	ft_env(void);
void	ft_export(char **args);
void	ft_unset(char **arg);
void	ft_cd(char **path);
void	ft_exec_bin(char *cmd, char **args, int shoulfork);

// UTILS
char	*ft_get_env(char *env);
t_env	*ft_new_node(char *key, char *value, int visible);
void	ft_env_add_front(t_env **envs, t_env *new);
t_mini	*mini_s(void);
void	ft_free_array(char **array);
char	**ft_join_envs(void);

//PARSERS
void	ft_parser(char *line, t_exec *exec_info);
void	ft_free_parser(t_exec *exec);
void	ft_parse_special(char *line, int *init_arg, t_exec *exec);
char	*ft_substr_clean(char *line, int init_arg, int len);
void	ft_parser_envs(char **envp);
void	ft_free_env(void);
int		split_key(char *env);

//REDIRECTS
void	ft_redirects(t_exec *exec_info);
void	ft_pipe(t_exec	*exec_info, int i, int fd_in);
void	ft_execute_cmd(t_exec *exec, int shouldfork);
void	ft_redirect_to(t_exec *exec_info, int i);
void	ft_redirect_from_single(t_exec *exec_info);
void	ft_redirect_from_double(t_exec *exec_info, int i);

#endif
