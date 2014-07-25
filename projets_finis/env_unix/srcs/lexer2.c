/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/22 16:06:47 by amusic            #+#    #+#             */
/*   Updated: 2014/06/16 18:27:44 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <stdlib.h>
#include <libft.h>

int	chk_blanck_space(char c, char **data, t_lex **lex)
{
	if (ft_strchr(BLANK_SPACE, c))
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		return (1);
	}
	return (0);
}

int	chk_separator(char c, char **data, t_lex **lex)
{
	if (ft_strchr(SEPARATOR, c))
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		addlex(lex, init_lex(ft_strdup(";"), sep));
		return (1);
	}
	return (0);
}

int	chk_logic(char c1, char c2, char **data, t_lex **lex)
{
	if (ft_strchr(LOGIC, c1) && ft_strchr(LOGIC, c2) && c2 != '\0')
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		if (c1 == '&')
			addlex(lex, init_lex(ft_strdup("&&"), log));
		if (c1 == '|')
			addlex(lex, init_lex(ft_strdup("||"), log));
		return (1);
	}
	return (0);
}

int	chk_pipe(char c, char **data, t_lex **lex)
{
	if (ft_strchr(PIPE, c))
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		addlex(lex, init_lex(ft_strdup("|"), pip));
		return (1);
	}
	return (0);
}

int	chk_redir(char *line, int *i, char **data, t_lex **lex)
{
	if (ft_strchr(REDIRECTION, line[*i]))
	{
		if (*data)
		{
			addlex(lex, init_lex(*data, -1));
			*data = NULL;
		}
		if (line[*i] == '<')
			addlex(lex, init_lex(ft_strdup("<"), redir));
		else if (line[*i + 1] == '>')
		{
			addlex(lex, init_lex(ft_strdup(">>"), redir));
			*i = *i + 1;
		}
		else
			addlex(lex, init_lex(ft_strdup(">"), redir));
		return (1);
	}
	return (0);
}
