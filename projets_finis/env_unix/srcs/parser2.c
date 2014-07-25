/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/23 18:33:21 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

int				get_log(t_lex *cmd, int *fd)
{
	t_lex		*lg;
	t_lex		*copy;
	int			i;

	i = 1;
	if (cmd->type >= 0)
	{
		copy = cmd;
		while ((lg = get_next_cmd(&cmd, log)))
		{
			i = parse_cmd(lg, fd);
			freelex(lg);
			if (copy != cmd)
			{
				while (copy->next != cmd)
					copy = copy->next;
				if (ft_strcmp(copy->data, "||") == 0 && i == 0)
					return (0);
				if (ft_strcmp(copy->data, "&&") == 0 && i != 0)
					return (i);
			}
			copy = cmd;
		}
	}
	return (i);
}

int				parse_cmd(t_lex *lex, int *fd)
{
	t_lex	*cmd;
	t_lex	*tmp;
	int		i;

	if (check_only_cmd(lex, fd, &i))
		return (i);
	cmd = NULL;
	tmp = lex;
	while (tmp && tmp->type != 4)
	{
		addlex(&cmd, init_lex(ft_strdup(tmp->data), tmp->type));
		tmp = tmp->next;
	}
	if (right_s_redir(fd, tmp, cmd, &i))
		return (i);
	if (right_d_redir(fd, tmp, cmd, &i))
		return (i);
	if (left_redir(fd, tmp, cmd, &i))
		return (i);
	if (lex->next != NULL && lex->next->next != NULL)
		onepipe(lex, fd, &i);
	freelex(cmd);
	return (i);
}

char			**add_to_tab(char **tab, char *str)
{
	int		len;
	char	**ret;
	char	*tmp;

	len = table_len(tab);
	ret = (char **)ft_memalloc((len + 2) * sizeof(char *));
	ret = ft_memcpy(ret, tab, len * sizeof(char *));
	if (str[0] != '"')
		ret[len] = ft_strdup(str);
	else
	{
		tmp = (char *)ft_memalloc(ft_strlen(str) - 1);
		tmp = ft_strncpy(tmp, str + 1, ft_strlen(str) - 2);
		ret[len] = tmp;
	}
	free(tab);
	return (ret);
}

t_lex			*getlex(t_lex *lex)
{
	t_lex	*cmd2;

	cmd2 = NULL;
	while (lex)
	{
		addlex(&cmd2, init_lex(ft_strdup(lex->data), lex->type));
		lex = lex->next;
	}
	return (cmd2);
}
