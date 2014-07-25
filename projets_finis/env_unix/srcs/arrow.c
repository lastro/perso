/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrow.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 19:13:59 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 19:26:56 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include <stdlib.h>
#include <term.h>
#include "libft.h"
extern int	g_prompt_len;

void	keye_up(t_env *e)
{
	tputs(tgetstr("up", NULL), 1, put_return);
	ROW -= MAXCOL;
}

void	keye_down(t_env *e)
{
	int		left;

	ROW += MAXCOL;
	tputs(tgetstr("do", NULL), 1, put_return);
	left = (g_prompt_len + ROW) % (MAXCOL);
	tputs(tgoto(tgetstr("ch", NULL), 0, left), 1, put_return);
}

void	keye_right(t_env *e)
{
	if (!((g_prompt_len + 3 + ROW) % MAXCOL))
		tputs(tgetstr("do", NULL), 1, put_return);
	tputs(tgetstr("cr", NULL), 1, put_return);
	ROW++;
	tputs(tgoto(tgetstr("ch", NULL), 0,
			(g_prompt_len + 2 + ROW) % MAXCOL), 1, put_return);
}

void	keye_left(t_env *e)
{
	if (!((g_prompt_len + 2 + ROW) % MAXCOL))
		tputs(tgetstr("up", NULL), 1, put_return);
	tputs(tgetstr("cr", NULL), 1, put_return);
	ROW--;
	tputs(tgoto(tgetstr("ch", NULL), 0,
			(g_prompt_len + 2 + ROW) % MAXCOL), 1, put_return);
}
