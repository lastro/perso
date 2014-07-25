/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_edit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 19:23:03 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 19:34:08 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_42sh.h"
#include "libft.h"
#include <term.h>
extern int	g_prompt_len;

void	delchar(t_env *e)
{
	ft_memmove((void *)(e->main_cmd + ROW - 1), (void *)(e->main_cmd + ROW),
		MAXROW - ROW);
	cur_top(e);
	e->main_cmd[--MAXROW] = '\0';
	ROW--;
	tputs(tgetstr("cd", NULL), 1, put_return);
	ft_putstr(e->main_cmd);
	cur_track(e);
}

void	writechar(char *r, t_env *e)
{
	ft_memmove((void *)(e->main_cmd + ROW + 1), (void *)(e->main_cmd + ROW),
		MAXROW - ROW);
	cur_top(e);
	e->main_cmd[ROW++] = r[0];
	MAXROW++;
	ft_putstr(e->main_cmd);
	cur_track(e);
}

int		chk_keys(char *r, t_env *e)
{
	if (r[0] >= 32 && r[0] <= 126)
		writechar(r, e);
	else if (r[0] == 10 && r[1] == 0 && r[2] == 0)
	{
		ft_putchar('\n');
		MAXROW = 0;
		return (0);
	}
	else if (r[0] == 4 && r[1] == 0 && r[2] == 0)
		exit(0);
	else if (r[0] == 127 && r[1] == 0 && r[2] == 0 && ROW)
		delchar(e);
	return (1);
}

int		charbychar(char *r, t_env *e)
{
	if (r != NULL)
	{
		if (r[1] == 0)
		{
			if (!chk_keys(r, e))
				return (0);
		}
		else if (r[0] == 27 && r[1] == 91 && r[2] == 68 && ROW)
			keye_left(e);
		else if (r[0] == 27 && r[1] == 91 && r[2] == 67
				&& ROW < MAXROW)
			keye_right(e);
		else if (r[0] == 27 && r[1] == 91 && r[2] == 65
				&& ROW > MAXCOL - 1)
			keye_up(e);
		else if (r[0] == 27 && r[1] == 91 && r[2] == 66
				&& ROW + MAXCOL < g_prompt_len + 2 + MAXROW)
			keye_down(e);
		else if (r[0] == 27 && r[1] == 91 && r[2] == 51 && ROW && ROW < MAXROW)
		{
			keye_right(e);
			delchar(e);
		}
	}
	return (1);
}
