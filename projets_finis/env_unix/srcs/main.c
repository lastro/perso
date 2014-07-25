/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 16:02:08 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/26 16:27:22 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <unistd.h>
#include <term.h>
#include "libft.h"
#include <signal.h>

t_alist	*g_al = NULL;
t_hlist	*g_his = NULL;
int		g_ret = 0;

static void	if_main(t_env *e)
{
	char		*line;
	t_lex		*lex;

	if (e->main_cmd)
	{
		signal(SIGINT, sigint2);
		add_history(e->main_cmd);
		line = chk_alias_and_var(e->main_cmd);
		lex = lexer_getdata(line, NULL, NULL, 0);
		parser(lex);
		freelex(lex);
		free(line);
		freer(0);
	}
}

static void	init_main(t_env **e)
{
	*e = init_data();
	init_termios(*e);
	window(0);
	create_env();
	signal_handler();
}

void		multi_dup(int *fd)
{
	if (fd[0] != 0)
	{
		dup2(fd[0], 0);
		close(fd[0]);
	}
	if (fd[1] != 1)
	{
		dup2(fd[1], 1);
		close(fd[1]);
	}
	if (fd[2] != -1)
		close(fd[2]);
	if (fd[3] != -1)
		close(fd[3]);
}

int			launch_cmd(char **split, int *fd)
{
	extern char		**environ;
	int				pid;
	char			*path;

	if ((pid = fork()) == -1)
	{
		ft_putendl_fd("42sh: fork failed", 2);
		return (256);
	}
	if (pid == 0)
	{
		multi_dup(fd);
		if (ft_strchr(split[0], '/'))
			execve(split[0], split, environ);
		else if ((path = ft_getenv("PATH")))
			launch_cmd_sub(split, path);
		ft_putstr_fd("42sh: no such file or directory: ", 2);
		ft_putendl_fd(split[0], 2);
		exit(127);
	}
	else
		wait(&pid);
	return (pid / 256);
}

int			main(void)
{
	t_env			*e;
	extern char		**environ;
	extern t_alist	*g_al;
	char			red[6];

	init_main(&e);
	while (42)
	{
		signal(SIGINT, sigint);
		if (tcsetattr(e->datas->fd, TCSADRAIN, CONF) == -1)
			exit(2);
		ft_bzero(red, 6);
		prompt();
		while (42)
		{
			if (charbychar(red, e) == 0)
				break ;
			ft_bzero(red, 6);
			read(0, red, 6);
		}
		if_main(e);
	}
	free_al(g_al);
	return (0);
}
