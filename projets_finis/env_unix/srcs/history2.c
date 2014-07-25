/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/05/28 18:49:20 by amusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

void	display_history(t_hlist *start)
{
	extern t_hlist	*g_his;

	if (start == g_his)
	{
		ft_putnbr(start->number);
		ft_putstr("  ");
		ft_putendl(start->value);
		start = start->next;
	}
	while (start != g_his)
	{
		ft_putnbr(start->number);
		ft_putstr("  ");
		ft_putendl(start->value);
		start = start->next;
	}
}

void	search_history(char *line)
{
	extern t_hlist	*g_his;
	t_hlist			*tmp;

	tmp = g_his;
	while (tmp->next != g_his)
	{
		if (!ft_strcmp(tmp->value, line))
			return (display_history(tmp));
		tmp = tmp->next;
	}
	if (!ft_strcmp(tmp->value, line))
		return (display_history(tmp));
}
