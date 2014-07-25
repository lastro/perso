/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_42sh.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 16:02:08 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/26 19:40:09 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_42SH_H
# define FT_42SH_H

# define BLACK "\033[30;m"
# define RED "\033[31;5;m"
# define GREEN "\033[32;m"
# define YELLOW "\033[33;m"
# define BLUE "\033[34;m"
# define PINK "\033[35;m"
# define L_BLUE "\033[36;m"
# define NORMAL "\033[37;00;0;m"

# define CONF	e->datas->config
# define ROW	e->datas->row
# define MAXROW	e->datas->maxrow
# define LENROW	(int)ft_strlen(e->prompt) + 2 + ROW
# define MAXCOL	e->datas->maxcol
# define T_CMD		0
# define T_SC		1
# define T_AND		2
# define T_OR		3
# define T_PIPE		4
# define T_REDIR	5
# define CONFIG		e->datas->config

# define SEPARATOR ";"
# define BLANK_SPACE " \t\n"
# define REDIRECTION "<>"
# define PIPE "|"
# define LOGIC "&|"

# define ALIAS_USG_1 "command alias. Type alias with no args to display "
# define ALIAS_USG_2 "alias. Type : alias name=\"value value\""
# define ALIAS_USG_3 " to set new alias. Exemple : alias lol=\"ls -l -a\"\n"

# define UNALIAS_USG_1 "command unalias. Type : \"unalias name\" to remove"
# define UNALIAS_USG_2 " \"name\" from alias list.\n"

typedef enum		e_type
{
	cmd,
	param,
	file,
	pip,
	redir,
	log,
	sep
}					t_type;

typedef struct		s_lex
{
	char			*data;
	int				type;
	struct s_lex	*next;
}					t_lex;

typedef	struct		s_alist
{
	char			*name;
	char			*value;
	struct s_alist	*next;
}					t_alist;

typedef	struct		s_hlist
{
	int				number;
	char			*value;
	struct s_hlist	*next;
	struct s_hlist	*prev;
}					t_hlist;

typedef struct		s_term
{
	int				fd;
	int				maxcol;
	int				row;
	int				maxrow;
	struct termios	*save;
	struct termios	*config;
}					t_term;

typedef struct		s_env
{
	char			*prompt;
	char			main_cmd[2048];
	t_term			*datas;
}					t_env;

/*
** function prototypes
*/

int					left_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i);
int					right_d_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i);
int					right_s_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i);
int					check_only_cmd(t_lex *lex, int *fd, int *i);
void				onepipe(t_lex *lex, int *fd, int *i);
int					get_log(t_lex *cmd, int *fd);
t_lex				*get_next_cmd(t_lex **lex, t_type t);
int					ft_putendl_ret(char *str);
int					parse_line(char **split, int *fd);
int					ft_history(char **line);
int					ft_unsetenv(char **split);
int					ft_setenv(char **split);
int					ft_env(char **split);
int					ft_cd(char **split);
int					ft_exit(char **split);
int					ft_alias(char **split);
int					launch_cmd(char **split, int *fd);
char				*join_data(t_lex *lex);
void				sigint2(int sig);
void				sigint(int sig);
void				sigstp(int sig);
t_lex				*getlex(t_lex *lex);
int					parse_cmd(t_lex *lex, int *fd);
int					check_lex(t_lex *lex);
void				parser(t_lex *lex);
char				**add_to_tab(char **tb, char *str);
int					chk_redir(char *line, int *i, char **data, t_lex **lex);
int					chk_pipe(char c, char **data, t_lex **lex);
int					chk_logic(char c1, char c2, char **data, t_lex **lex);
int					chk_separator(char c, char **data, t_lex **lex);
int					chk_blanck_space(char c, char **data, t_lex **lex);
t_lex				*lexer_getdata(char *line, t_lex *lex, char *data, int i);
void				freelex(t_lex *lex);
void				addlex(t_lex **lex, t_lex *new);
t_lex				*init_lex(char *data, int type);
void				launch_cmd_sub(char **split, char *path);
char				*ft_strjoin_triple(char *s1, char *s2, char *s3);
void				create_env(void);
char				*ft_getenv(char *str);
int					prompt(void);
void				reg_prompt(void);
char				*home_path(void);
int					check_color(char *p);
void				put_dir(char *pwd);
void				put_path(char *pwd, char *name);
void				multi_dup(int *fd);
void				ft_setenv_sub1(char **split);
void				ft_setenv_sub2(char **split);
char				*chk_alias_and_var(char *line);
char				*alias_value(char *buff);
char				*alias_name(char *buff);
void				creat_alias(void);
void				free_al(t_alist *g_al);
void				ft_new_alias(char **split);
void				ft_display_alias(void);
void				add_history(char *line);
void				search_history(char *line);
void				display_history(t_hlist *start);
char				*join_arg(char **split);
char				*chk_var(char *line);
int					ft_echo(char **split);
int					ft_unalias(char **split);
void				signal_handler(void);
void				window(int sig);
void				init_term(t_env *e);
t_env				*init_data(void);
void				init_termios(t_env *e);
void				delchar(t_env *e);
void				writechar(char *read, t_env *e);
int					chk_keys(char *read, t_env *e);
int					charbychar(char *read, t_env *e);
void				keye_up(t_env *e);
void				keye_down(t_env *e);
void				keye_right(t_env *e);
void				keye_left(t_env *e);
void				cur_top(t_env *e);
void				cur_track(t_env *e);
int					exit_term(t_env *e);
int					put_return(int c);
void				prompt_trm(t_env *e);
void				display_prompt(t_env *e);
void				freer(int sig);
void				fg(int sig);
void				bg(int sig);
void				retexit(int sig);
#endif
