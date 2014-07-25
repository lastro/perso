/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/11 18:17:04 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

void			del_one_history(void)
{
	extern t_hlist		*g_his;
	t_hlist				*tmp;

	tmp = g_his->next;
	g_his->prev->next = g_his->next;
	g_his->next->prev = g_his->prev;
	free(g_his->value);
	free(g_his);
	g_his = tmp;
}

int				ft_history(char **line)
{
	extern t_hlist	*g_his;
	int				i;
	t_hlist			*tmp;

	if (!line[1])
	{
		i = 0;
		tmp = g_his->prev;
		while (i < 9)
		{
			tmp = tmp->prev;
			if (tmp == g_his)
			{
				display_history(g_his);
				return (0);
			}
			i++;
		}
		display_history(tmp);
	}
	else
		search_history(join_arg(&line[1]));
	return (0);
}

static void		creat_history(char *line)
{
	extern t_hlist	*g_his;
	t_hlist			*new_entry;

	new_entry = (t_hlist *)malloc(sizeof(t_hlist));
	new_entry->number = 1;
	new_entry->value = ft_strdup(line);
	new_entry->next = new_entry;
	new_entry->prev = new_entry;
	g_his = new_entry;
}

static void		add_one_history(char *line)
{
	extern t_hlist	*g_his;
	t_hlist			*new_entry;

	if (g_his->prev->number >= 1024)
		del_one_history();
	new_entry = (t_hlist *)malloc(sizeof(t_hlist));
	new_entry->number = g_his->prev->number + 1;
	new_entry->value = ft_strdup(line);
	new_entry->next = g_his;
	new_entry->prev = g_his->prev;
	g_his->prev->next = new_entry;
	g_his->prev = new_entry;
}

void			add_history(char *line)
{
	extern t_hlist	*g_his;

	if (!g_his)
		creat_history(line);
	else
		add_one_history(line);
}
