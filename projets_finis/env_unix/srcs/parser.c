/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/18 19:01:46 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <libft.h>

extern int		g_ret;

static int		*getfd(int a, int b, int c, int d)
{
	int		*ret;

	ret = (int *)malloc(4 * sizeof(int));
	ret[0] = a;
	ret[1] = b;
	ret[2] = c;
	ret[3] = d;
	return (ret);
}

void			onepipe(t_lex *lex, int *fd, int *i)
{
	char	**cmd1;
	t_lex	*cmd2;
	int		pip[2];
	int		*fd1;

	cmd1 = ft_memalloc(sizeof(char *));
	while (lex && lex->type <= 1)
	{
		cmd1 = add_to_tab(cmd1, lex->data);
		lex = lex->next;
	}
	lex = lex->next;
	cmd2 = getlex(lex);
	pipe(pip);
	fd1 = getfd(fd[0], pip[1], fd[2], pip[0]);
	parse_line(cmd1, fd1);
	free(fd1);
	close(pip[1]);
	if (cmd2 == NULL)
		cmd2 = init_lex(NULL, -1);
	fd1 = getfd(pip[0], fd[1], pip[1], fd[3]);
	*i = parse_cmd(cmd2, fd1);
	free(fd1);
	freelex(cmd2);
	close(pip[0]);
}

int				check_only_cmd(t_lex *lex, int *fd, int *i)
{
	t_lex	*tmp;
	char	**cmd;

	if (lex == NULL && (*i = g_ret))
		return (1);
	if (lex->type == -1 && (*i = g_ret))
		return (1);
	tmp = lex;
	while (tmp)
	{
		if (tmp->type > 1 || tmp->type < 0)
			return (0);
		tmp = tmp->next;
	}
	tmp = lex;
	cmd = ft_memalloc(sizeof(char *));
	while (tmp)
	{
		cmd = add_to_tab(cmd, tmp->data);
		tmp = tmp->next;
	}
	*i = parse_line(cmd, fd);
	return (1);
}

t_lex			*get_next_cmd(t_lex **lex, t_type t)
{
	t_lex	*ret;
	t_lex	*tmp;

	ret = NULL;
	tmp = *lex;
	if (tmp == NULL)
		return (NULL);
	while (tmp && tmp->type != t)
	{
		addlex(&ret, init_lex(ft_strdup(tmp->data), tmp->type));
		tmp = tmp->next;
	}
	if (ret == NULL)
		addlex(&ret, init_lex(NULL, -1));
	if (tmp)
		*lex = tmp->next;
	else
		*lex = tmp;
	return (ret);
}

void			parser(t_lex *lex)
{
	t_lex	*cmd;
	t_lex	*tmp;
	int		*fd;
	int		ret;

	tmp = lex;
	if (!lex)
		return ;
	if (check_lex(lex))
		return ;
	fd = getfd(0, 1, -1, -1);
	while ((cmd = get_next_cmd(&tmp, sep)))
	{
		ret = get_log(cmd, fd);
		freelex(cmd);
	}
	g_ret = ret;
	free(fd);
}
