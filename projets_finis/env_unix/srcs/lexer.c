/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/23 18:38:29 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <stdlib.h>
#include <libft.h>

static int	chk_quote(char *line, int *i, char **data, t_lex **lex)
{
	if (line[*i] == '"')
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		(*i)++;
		*data = ft_append(*data, '"');
		while (line[*i] && line[*i] != '"')
		{
			*data = ft_append(*data, line[*i]);
			(*i)++;
		}
		*data = ft_append(*data, '"');
		if (!line[*i])
			(*i)--;
		return (1);
	}
	return (0);
}

static void	lexer_sub(t_lex *lex)
{
	int		state;
	int		c;

	state = cmd;
	c = 0;
	while (lex)
	{
		if (lex->type == -1)
			lex->type = state;
		state = lex->type;
		if (state == cmd && (c = 1))
			state = param;
		else if (state == file && c == 1)
			state = param;
		else if (state == file || state == sep || state == pip || state == log)
		{
			state = cmd;
			c = 0;
		}
		else if (state == redir)
			state = file;
		lex = lex->next;
	}
}

t_lex		*init_lex(char *data, int type)
{
	t_lex	*ret;

	ret = (t_lex *)malloc(sizeof(t_lex));
	ret->data = data;
	ret->type = type;
	ret->next = NULL;
	return (ret);
}

void		addlex(t_lex **lex, t_lex *new)
{
	t_lex	*tmp;

	if (*lex == NULL)
		*lex = new;
	else
	{
		tmp = *lex;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_lex		*lexer_getdata(char *line, t_lex *lex, char *data, int i)
{
	while (line[i])
	{
		if (chk_quote(line, &i, &data, &lex))
			;
		else if (chk_blanck_space(line[i], &data, &lex))
			;
		else if (chk_separator(line[i], &data, &lex))
			;
		else if (chk_logic(line[i], line[i + 1], &data, &lex))
			i++;
		else if (chk_redir(line, &i, &data, &lex))
			;
		else if (chk_pipe(line[i], &data, &lex))
			;
		else
			data = ft_append(data, line[i]);
		i++;
	}
	if (data)
	{
		addlex(&lex, init_lex(data, -1));
		data = NULL;
	}
	lexer_sub(lex);
	return (lex);
}
