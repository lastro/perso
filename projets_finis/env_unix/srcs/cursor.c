/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 14:55:39 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 21:49:11 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <term.h>
extern int	g_prompt_len;

void	cur_top(t_env *e)
{
	int		res;
	int		left;

	res = (g_prompt_len + 2 + ROW) / (MAXCOL);
	left = g_prompt_len + 2;
	while (res-- > 0)
		tputs(tgetstr("up", NULL), 1, put_return);
	tputs(tgetstr("cr", NULL), 1, put_return);
	tputs(tgoto(tgetstr("ch", NULL), 0, left), 1, put_return);
}

void	cur_track(t_env *e)
{
	int		res;
	int		left;

	res = (g_prompt_len + 2 + MAXROW - 1) / (MAXCOL);
	left = (g_prompt_len + 2 + ROW) % (MAXCOL);
	while (res-- > 0)
		tputs(tgetstr("up", NULL), 1, put_return);
	res = (g_prompt_len + 2 + ROW) / (MAXCOL);
	while (res-- > 0)
		tputs(tgetstr("do", NULL), 1, put_return);
	tputs(tgetstr("cr", NULL), 1, put_return);
	tputs(tgoto(tgetstr("ch", NULL), 0, left), 1, put_return);
}
