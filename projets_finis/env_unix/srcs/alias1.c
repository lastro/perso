/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/25 19:32:36 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

static char		*is_alias(char *cmd)
{
	t_alist			*tmp;
	extern t_alist	*g_al;

	tmp = g_al;
	while (tmp)
	{
		if (!ft_strcmp(cmd, tmp->name))
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

char			*join_data(t_lex *lex)
{
	char	*line;
	char	*buf;

	if (lex)
	{
		line = ft_strdup(lex->data);
		lex = lex->next;
		while (lex)
		{
			buf = line;
			line = ft_strjoin_triple(line, " ", lex->data);
			free(buf);
			lex = lex->next;
		}
		return (line);
	}
	return (NULL);
}

static char		*chk_alias(char *line)
{
	t_lex	*lex;
	t_lex	*tmp;
	char	*cmd;

	lex = lexer_getdata(line, NULL, NULL, 0);
	if (!lex)
		return (ft_strdup(line));
	tmp = lex;
	while (lex)
	{
		if (lex->type == 0)
		{
			if ((cmd = is_alias(lex->data)) != NULL)
			{
				free(lex->data);
				lex->data = cmd;
			}
		}
		lex = lex->next;
	}
	line = join_data(tmp);
	freelex(tmp);
	return (line);
}

char			*chk_alias_and_var(char *line)
{
	line = chk_alias(line);
	line = chk_var(line);
	return (line);
}

int				ft_alias(char **split)
{
	if (split && !split[1])
		ft_display_alias();
	else if (split[2] && split[1][ft_strlen(split[1]) - 1] == '=')
		ft_new_alias(split);
	else
	{
		ft_putstr_fd(ALIAS_USG_1, 2);
		ft_putstr_fd(ALIAS_USG_2, 2);
		ft_putstr_fd(ALIAS_USG_3, 2);
		return (127);
	}
	return (0);
}
