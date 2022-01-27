/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elima-me <elima-me@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 22:30:36 by lyuri-go          #+#    #+#             */
/*   Updated: 2022/01/27 19:37:35 by lyuri-go         ###   ########.fr       */
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

enum e_errors {
	ERR_NO_NUMERIC_ARGS,
	ERR_TOO_MANY_ARGS,	
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
int		ft_signals(void);
void	ft_load_history(void);
void	ft_add_history(char *in);
void	ft_free(t_exec *exec);
void	handle_nothing(int sig);
void	handle_standard(int sig);
void	ft_signals_standard_exec(int sig);

// CMDS
void	ft_echo(char **argv);
void	ft_pwd(void);
void	ft_exit(t_exec *exec);
void	ft_env(void);
void	ft_export(char **args);
void	ft_unset(char **arg);
void	ft_cd(char **path, int should_fork);
void	ft_exec_bin(char *cmd, char **args, int shoulfork);
void	ft_parse_home(int should_fork);

// UTILS
char	*ft_get_env(char *env);
t_env	*ft_new_node(char *key, char *value, int visible);
void	ft_env_add_front(t_env **envs, t_env *new);
t_mini	*mini_s(void);
void	ft_free_array(char **array);
char	**ft_join_envs(void);
int		not_have_line(t_exec *exec_info, char *line);
void	check_pipe_and_last(t_exec *exec_info, int fd[2], int pid, int fdi_to);
void	wait_and_handle_sig(int pid);
void	ft_wait_get_status(int pid, int env);

//PARSERS
void	ft_parser(char *line, t_exec *exec_info);
void	ft_free_parser(t_exec *exec);
void	ft_parse_special(char *line, int *init_arg, t_exec *exec);
char	*ft_substr_clean(char *line, int init_arg, int len);
void	ft_parser_envs(char **envp);
void	ft_free_env(void);
int		split_key(char *env);
int		ft_is_special(char character);
int		ft_validate_quotes(char *line);
int		ft_validate_redirects(t_exec *exec_info);

//REDIRECTS
void	ft_redirects(t_exec *exec_info, int i, int fdi, int is_redirect);
void	ft_pipe(t_exec	*exec_info, int i, int fd_in);
void	ft_execute_cmd(t_exec *exec, int shouldfork);
void	ft_redirect_to(t_exec *exec_info, int i, int fdi);
void	ft_redirect_from_single(t_exec *exec_info, int i);
void	ft_redirect_from_double(t_exec *exec_info, int i,
			int pid, int commands);
void	ft_redirect_from(t_exec *exec_info, int i);
int		ft_redi_from_doub_last(t_exec *ex_inf, int fd[2], int pid, int fdt);
int		check_path(t_exec *exec_info);
void	ft_redirect_from_single_init(t_exec *exec_info, int fd[2]);

#endif
