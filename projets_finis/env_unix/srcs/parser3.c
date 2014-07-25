/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/20 15:00:26 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libft.h>

const char	*g_cmd[10] =
{
	"unalias",
	"cd",
	"setenv",
	"unsetenv",
	"exit",
	"alias",
	"history",
	"echo",
	"env",
	NULL
};

int			(*g_fct[9])(char **) =
{
	&ft_unalias,
	&ft_cd,
	&ft_setenv,
	&ft_unsetenv,
	&ft_exit,
	&ft_alias,
	&ft_history,
	&ft_echo,
	&ft_env,
};

int			right_s_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i)
{
	if (tmp && !ft_strcmp(tmp->data, ">"))
	{
		fd[1] = open(tmp->next->data, O_CREAT | O_TRUNC | O_WRONLY, S_IRWXU);
		tmp = tmp->next->next;
		while (tmp)
		{
			addlex(&cmd, init_lex(ft_strdup(tmp->data), tmp->type));
			tmp = tmp->next;
		}
		*i = parse_cmd(cmd, fd);
		freelex(cmd);
		return (1);
	}
	return (0);
}

int			right_d_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i)
{
	if (tmp && !ft_strcmp(tmp->data, ">>"))
	{
		fd[1] = open(tmp->next->data, O_CREAT | O_APPEND | O_WRONLY, S_IRWXU);
		tmp = tmp->next->next;
		while (tmp)
		{
			addlex(&cmd, init_lex(ft_strdup(tmp->data), tmp->type));
			tmp = tmp->next;
		}
		*i = parse_cmd(cmd, fd);
		freelex(cmd);
		return (1);
	}
	return (0);
}

int			left_redir(int *fd, t_lex *tmp, t_lex *cmd, int *i)
{
	if (tmp && !ft_strcmp(tmp->data, "<"))
	{
		fd[0] = open(tmp->next->data, O_RDONLY);
		tmp = tmp->next->next;
		while (tmp)
		{
			addlex(&cmd, init_lex(ft_strdup(tmp->data), tmp->type));
			tmp = tmp->next;
		}
		*i = parse_cmd(cmd, fd);
		freelex(cmd);
		return (1);
	}
	return (0);
}

static int	launch_env(char **split, int *fd, int i)
{
	int				pid;

	if ((pid = fork()) == -1)
	{
		ft_putendl_fd("42sh: fork failed", 2);
		return (127);
	}
	if (pid == 0)
	{
		multi_dup(fd);
		exit(g_fct[i](split));
	}
	else
		wait(&pid);
	return (0);
}

int			parse_line(char **split, int *fd)
{
	extern char	**environ;
	int			i;

	i = 0;
	while (environ[i] && ft_strncmp(environ[i], "_=", 2))
		i++;
	free(environ[i]);
	environ[i] = ft_strjoin("_=", split[0]);
	i = 0;
	while (g_cmd[i])
	{
		if (!ft_strcmp(g_cmd[i], split[0]))
		{
			if (i <= 4 || (i == 5 && table_len(split) != 1))
				i = g_fct[i](split);
			else
				i = launch_env(split, fd, i);
			free_table(split);
			return (i);
		}
		i++;
	}
	i = launch_cmd(split, fd);
	free_table(split);
	return (i);
}
