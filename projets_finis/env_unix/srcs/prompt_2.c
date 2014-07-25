/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:15:10 by amusic            #+#    #+#             */
/*   Updated: 2014/06/26 21:48:36 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>
extern int	g_prompt_len;

void		reg_prompt(void)
{
	char		*prompt;
	int			i;
	extern char	**environ;

	i = 0;
	prompt = NULL;
	while (environ[i] != 0)
	{
		if (ft_strncmp(environ[i], "USER", 4) == 0)
		{
			prompt = ft_strdup(&environ[i][5]);
			break ;
		}
		i++;
	}
	if (prompt != NULL)
	{
		ft_putstr(prompt);
		g_prompt_len = g_prompt_len + ft_strlen(prompt);
		free(prompt);
	}
	ft_putstr("@>");
	g_prompt_len = g_prompt_len + 2;
}

char		*home_path(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i] != 0)
	{
		if (ft_strncmp(environ[i], "HOME", 4) == 0)
			return (ft_strjoin(&environ[i][5], "/.42shrc"));
		i++;
	}
	return (NULL);
}

int			check_color(char *p)
{
	if (p[0] == '[' && p[2] == ']')
	{
		if (p[1] == 'B')
			ft_putstr(BLUE);
		if (p[1] == 'K')
			ft_putstr(BLACK);
		if (p[1] == 'R')
			ft_putstr(RED);
		if (p[1] == 'G')
			ft_putstr(GREEN);
		if (p[1] == 'Y')
			ft_putstr(YELLOW);
		if (p[1] == 'P')
			ft_putstr(PINK);
		if (p[1] == 'L')
			ft_putstr(L_BLUE);
		if (p[1] == 'N')
			ft_putstr(NORMAL);
		if (p[1] == 'B' || p[1] == 'K' || p[1] == 'R' || p[1] == 'G'
			|| p[1] == 'Y' || p[1] == 'P' || p[1] == 'L' || p[1] == 'N')
			return (1);
	}
	return (0);
}

void		put_dir(char *pwd)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(pwd, '/');
	while (split[i] != 0)
		i++;
	i--;
	ft_putchar('/');
	ft_putstr(split[i]);
	g_prompt_len = g_prompt_len + 1 + ft_strlen(split[i]);
	free_table(split);
}

void		put_path(char *pwd, char *name)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(pwd, '/');
	while (split[i] != 0)
	{
		if (ft_strcmp(split[i], name) == 0)
			break ;
		i++;
	}
	if (split[i])
	{
		ft_putchar('~');
		g_prompt_len++;
	}
	else
		i = -1;
	while (split[++i] != 0)
	{
		ft_putchar('/');
		ft_putstr(split[i]);
		g_prompt_len = g_prompt_len + 1 + ft_strlen(split[i]);
	}
	free_table(split);
}
