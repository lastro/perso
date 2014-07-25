/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsaintot <nsaintot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/26 20:03:56 by amusic            #+#    #+#             */
/*   Updated: 2014/06/26 22:08:44 by nsaintot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <fcntl.h>
#include <libft.h>

int				g_prompt_len = 0;

static void		prompt_sub3(char c, char *pwd, char *name)
{
	if (c == 'n' && name != NULL)
	{
		g_prompt_len = g_prompt_len + ft_strlen(name);
		ft_putstr(name);
	}
	else if (c == '.' && pwd != NULL)
		put_dir(pwd);
	else if (c == '~' && pwd != NULL && name != NULL)
		put_path(pwd, name);
}

static void		prompt_sub2(char *name, char *pwd, char *prt)
{
	int	i;

	i = 0;
	while (prt[i] != 0 && prt[i] != '\'')
	{
		if (prt[i] == 'n' || prt[i] == '.' || prt[i] == '~')
		{
			if (i > 0 && prt[i - 1] == '%')
			{
				prompt_sub3(prt[i++], pwd, name);
				continue ;
			}
		}
		if (prt[i] == '%' && (prt[i + 1] == 'n'
			|| prt[i + 1] == '.' || prt[i + 1] == '~'))
			i++;
		else if (check_color(&prt[i]) == 0)
		{
			ft_putchar(prt[i++]);
			g_prompt_len++;
		}
		else
			i += 3;
	}
}

static void		prompt_sub1(char *prompt)
{
	char		*name;
	char		*pwd;
	int			i;
	extern char	**environ;

	i = 0;
	pwd = NULL;
	name = NULL;
	while (environ[i] != 0)
	{
		if (ft_strncmp(environ[i], "USER=", 5) == 0)
			name = ft_strdup(&environ[i][5]);
		if (ft_strncmp(environ[i], "PWD=", 4) == 0)
			pwd = ft_strdup(&environ[i][4]);
		i++;
	}
	prompt_sub2(name, pwd, prompt);
	if (pwd)
		free(pwd);
	if (name)
		free(name);
	ft_putstr(NORMAL);
}

static void		custom_prompt(int fd)
{
	char	*buff;

	while (get_next_line(fd, &buff))
	{
		if (buff[0] != '\0')
		{
			if (ft_strncmp(buff, "PROMPT=", 7) == 0)
			{
				prompt_sub1(&buff[8]);
				free(buff);
				return ;
			}
		}
		free(buff);
	}
	reg_prompt();
}

int				prompt(void)
{
	int		fd;
	char	*path;

	g_prompt_len = 0;
	path = home_path();
	if ((fd = open(path, O_RDONLY)) != -1)
	{
		custom_prompt(fd);
		close(fd);
	}
	else
		reg_prompt();
	ft_putstr("  ");
	free(path);
	return (1);
}
