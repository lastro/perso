/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:27:53 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/11 18:42:49 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

void		(*g_set[3])(char **) =
{
	&ft_setenv_sub1,
	&ft_setenv_sub2,
};

int		ft_env(char **split)
{
	int			i;
	extern char	**environ;

	if (table_len(split) != 1)
	{
		ft_putendl_fd("env: wrong number of arguments", 2);
		return (127);
	}
	i = 0;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		i++;
	}
	return (0);
}

int		ft_setenv(char **split)
{
	extern char	**environ;

	if (table_len(split) < 2 && table_len(split) > 3)
	{
		ft_putendl_fd("setenv: wrong number of arguments", 2);
		return (127);
	}
	g_set[table_len(split) - 2](split);
	return (0);
}

int		ft_unsetenv(char **split)
{
	int			i;
	extern char	**environ;

	if (table_len(split) != 2)
	{
		ft_putendl_fd("unsetenv: wrong number of arguments", 2);
		return (127);
	}
	i = 0;
	while (environ[i] && ft_strncmp(environ[i], split[1], ft_strlen(split[1])))
		i++;
	free(environ[i]);
	while (environ[i + 1])
	{
		environ[i] = environ[i + 1];
		i++;
	}
	environ[i] = NULL;
	return (0);
}

char	*ft_getenv(char *str)
{
	int			i;
	extern char	**environ;
	char		*buf;

	i = 0;
	buf = ft_strjoin(str, "=");
	while (environ[i])
	{
		if (!ft_strncmp(environ[i], buf, ft_strlen(buf)))
		{
			free(buf);
			return (ft_strchr(environ[i], '=') + 1);
		}
		i++;
	}
	free(buf);
	return (NULL);
}

void	create_env(void)
{
	extern char	**environ;
	char		**tmp;
	int			i;

	tmp = malloc((table_len(environ) + 1) * sizeof(char*));
	i = 0;
	while (environ[i])
	{
		tmp[i] = ft_strdup(environ[i]);
		i++;
	}
	environ = tmp;
	creat_alias();
}
