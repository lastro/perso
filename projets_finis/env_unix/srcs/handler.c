/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/24 19:27:13 by nsaintot          #+#    #+#             */
/*   Updated: 2014/06/26 15:51:59 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <termios.h>
#include "ft_42sh.h"

t_env signal_handler(t_env *e)
{
	e = init_data();
	init_term(e);
	obtain_termios(e);
	(void)argv;
	e->success = 0;
	return (e);
}
