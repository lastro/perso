/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unalias.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/23 18:43:36 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

static int		remove_alias(t_alist *tmp, t_alist *prev)
{
	extern t_alist	*g_al;

	if (prev != NULL)
		prev->next = tmp->next;
	else
		g_al = g_al->next;
	free(tmp->name);
	free(tmp->value);
	free(tmp);
	return (0);
}

int				ft_unalias(char **split)
{
	extern t_alist	*g_al;
	t_alist			*tmp;
	t_alist			*prev;

	prev = NULL;
	if (table_len(split) == 2)
	{
		tmp = g_al;
		while (tmp)
		{
			if (!ft_strcmp(tmp->name, split[1]))
				return (remove_alias(tmp, prev));
			prev = tmp;
			tmp = tmp->next;
		}
		ft_putendl_fd("This alias does not exist", 2);
		return (1);
	}
	else
	{
		ft_putstr_fd(UNALIAS_USG_1, 2);
		ft_putstr_fd(UNALIAS_USG_2, 2);
		return (127);
	}
}
