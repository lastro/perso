/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libaux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 23:36:33 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/11 18:37:39 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>
#include <unistd.h>

char		*ft_strjoin_triple(char *s1, char *s2, char *s3)
{
	char	*buf;
	char	*ret;

	buf = ft_strjoin(s2, s3);
	ret = ft_strjoin(s1, buf);
	free(buf);
	return (ret);
}

void		freelex(t_lex *lex)
{
	t_lex	*tmp;

	while (lex)
	{
		tmp = lex->next;
		free(lex->data);
		free(lex);
		lex = tmp;
	}
}

void		free_al(t_alist *g_al)
{
	t_alist	*tmp;

	while (g_al)
	{
		tmp = g_al->next;
		free(g_al->name);
		free(g_al->value);
		free(g_al);
		g_al = tmp;
	}
}

int			ft_putendl_ret(char *str)
{
	ft_putendl_fd(str, 2);
	return (1);
}
