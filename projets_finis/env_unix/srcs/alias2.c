/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alias2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/23 18:43:36 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>
#include <fcntl.h>

void		ft_display_alias(void)
{
	extern t_alist	*g_al;
	t_alist			*tmp;

	tmp = g_al;
	while (tmp)
	{
		ft_putstr(tmp->name);
		ft_putstr("='");
		ft_putstr(tmp->value);
		ft_putendl("'");
		tmp = tmp->next;
	}
}

char		*join_arg(char **split)
{
	char	*line;
	char	*buf;
	int		i;

	i = 1;
	line = ft_strdup(split[0]);
	while (split[i] != 0)
	{
		buf = line;
		line = ft_strjoin_triple(line, " ", split[i]);
		free(buf);
		i++;
	}
	return (line);
}

void		ft_new_alias(char **split)
{
	t_alist			*new_al;
	extern t_alist	*g_al;

	new_al = (t_alist *)malloc(sizeof(t_alist));
	new_al->name = ft_strdup(split[1]);
	new_al->name[ft_strlen(new_al->name) - 1] = 0;
	new_al->value = join_arg(&split[2]);
	new_al->next = g_al;
	g_al = new_al;
}

static void	creat_alias_sub(char *buff)
{
	t_alist			*new_al;
	extern t_alist	*g_al;

	new_al = (t_alist *)malloc(sizeof(t_alist));
	new_al->name = alias_name(buff);
	new_al->value = alias_value(buff);
	new_al->next = g_al;
	g_al = new_al;
}

void		creat_alias(void)
{
	int				fd;
	char			*path;
	char			*buff;

	path = home_path();
	if ((fd = open(path, O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &buff))
		{
			if (buff[0] != '\0' && (ft_strncmp(buff, "alias ", 6) == 0))
				creat_alias_sub(buff);
			free(buff);
		}
		close(fd);
	}
	free(path);
}
