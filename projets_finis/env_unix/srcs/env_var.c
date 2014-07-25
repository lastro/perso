/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/11 18:49:57 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

extern int		g_ret;

static char		*is_var(char *cmd)
{
	char		*tmp;

	if (!ft_strcmp(cmd, "$?"))
		return (ft_itoa(g_ret));
	if (cmd[0] == '$')
	{
		tmp = ft_getenv(&cmd[1]);
		if (tmp)
			return (ft_strdup(tmp));
		return (NULL);
	}
	return (NULL);
}

char			*chk_var(char *line)
{
	t_lex	*lex;
	t_lex	*tmp;
	char	*cmd;

	lex = lexer_getdata(line, NULL, NULL, 0);
	if (!lex)
		return (line);
	free(line);
	tmp = lex;
	while (lex)
	{
		if (lex->type == 0 || lex->type == 1)
		{
			if ((cmd = is_var(lex->data)) != NULL)
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
