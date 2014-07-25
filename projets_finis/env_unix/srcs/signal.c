/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/25 04:00:25 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/26 20:00:41 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <term.h>
#include <sys/ioctl.h>
#include <signal.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_42sh.h>

void		window(int sig)
{
	t_env	*e;

	e = init_data();
	(void)sig;
	init_term(e);
	e->datas->maxcol = tgetnum("co");
}

void		signal_handler(void)
{
	signal(SIGTSTP, bg);
	signal(SIGCONT, fg);
	signal(SIGQUIT, retexit);
	signal(SIGINT, freer);
	signal(SIGWINCH, window);
}

void		sigint(int sig)
{
	(void)sig;
	write(1, "\n", 1);
	freer(0);
	prompt();
}

void		sigint2(int sig)
{
	(void)sig;
}
