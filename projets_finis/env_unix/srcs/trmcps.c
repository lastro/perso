/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trmcps.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 19:21:53 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 01:30:59 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <stdlib.h>
#include "libft.h"
#include "ft_42sh.h"

void		init_term(t_env *e)
{
	char	*term;
	int		success;

	if (!(term = getenv("TERM")))
	{
		ft_putendl_fd("No terminal type in your environment.", 2);
		exit(2);
	}
	if ((success = tgetent(e->main_cmd, term)) < 0)
		ft_putendl_fd("Could not access termcap database.", 2);
	if (success == 0)
		ft_putendl_fd("Your terminal type is not defined.", 2);
}

t_env		*init_data(void)
{
	static t_env	*e = NULL;

	if (e == NULL)
	{
		if (!(e = (t_env *)ft_memalloc(sizeof(*e))))
		{
			ft_putendl_fd("t_env malloc failed.", 2);
			exit(1);
		}
		if (!(e->datas = (t_term *)ft_memalloc(sizeof(*e->datas))))
		{
			ft_putendl_fd("t_term malloc failed.", 2);
			exit(1);
		}
		e->prompt = "nsaintot @ [/42sh] >>>";
		e->datas->row = 0;
	}
	return (e);
}

void		init_termios(t_env *e)
{
	e->datas->save = (struct termios *)ft_memalloc(sizeof(struct termios));
	tcgetattr(e->datas->fd, e->datas->save);
	CONF = (struct termios *)ft_memalloc(sizeof(struct termios));
	CONF = ft_memcpy(CONF, e->datas->save, sizeof(*(e->datas->save)));
	CONF->c_lflag &= ~(ICANON);
	CONF->c_lflag &= ~(ECHO);
	CONF->c_cc[VMIN] = 1;
	CONF->c_cc[VTIME] = 0;
	if (tcsetattr(e->datas->fd, TCSADRAIN, CONF) == -1)
		exit(2);
}
