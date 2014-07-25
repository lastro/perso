/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 19:18:19 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 19:59:13 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_42sh.h"
#include <term.h>
#include <sys/ioctl.h>

void		fg(int sig)
{
	t_env	*e;

	e = init_data();
	(void)sig;
	tcsetattr(e->datas->fd, TCSADRAIN, e->datas->config);
	signal(SIGTSTP, bg);
	prompt();
}

void		freer(int sig)
{
	t_env	*e;

	e = init_data();
	(void)sig;
	ft_bzero(e->main_cmd, 2048);
	e->datas->row = 0;
	e->datas->maxrow = 0;
}

void		retexit(int sig)
{
	t_env	*e;

	e = init_data();
	(void)sig;
	exit(0);
}

void		bg(int sig)
{
	char	var[2];
	t_env	*e;

	if (sig == SIGTSTP)
	{
		e = init_data();
		var[0] = e->datas->config->c_cc[VSUSP];
		var[1] = 0;
		tputs(tgoto(tgetstr("cm", NULL), 0, 0), 1, put_return);
		tputs(tgetstr("cd", NULL), 1, put_return);
		tcsetattr(e->datas->fd, TCSADRAIN, e->datas->save);
		signal(SIGTSTP, SIG_DFL);
		ioctl(0, TIOCSTI, var);
	}
}

int			put_return(int c)
{
	t_env	*e;

	e = init_data();
	ft_putchar_fd(c, e->datas->fd);
	return (1);
}
