/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:27:53 by amusic            #+#    #+#             */
/*   Updated: 2014/06/23 18:44:02 by tlepetit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

void		ft_setenv_sub1(char **split)
{
	int			i;
	char		**tmp;
	extern char	**environ;

	tmp = malloc((table_len(environ) + 2) * sizeof(char *));
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], split[1], ft_strlen(split[1]))
			&& environ[i][ft_strlen(split[1])] == '=')
		{
			free(environ[i]);
			environ[i] = ft_strjoin(split[1], "=");
			free(tmp);
			return ;
		}
		tmp[i] = environ[i];
	}
	tmp[i] = ft_strjoin(split[1], "=");
	tmp[i + 1] = NULL;
	free(environ);
	environ = tmp;
}

void		ft_setenv_sub2(char **split)
{
	int			i;
	char		**tmp;
	extern char	**environ;

	tmp = malloc((table_len(environ) + 2) * sizeof(char *));
	i = -1;
	while (environ[++i])
	{
		if (!ft_strncmp(environ[i], split[1], ft_strlen(split[1]))
			&& environ[i][ft_strlen(split[1])] == '=')
		{
			free(environ[i]);
			environ[i] = ft_strjoin_triple(split[1], "=", split[2]);
			free(tmp);
			return ;
		}
		tmp[i] = environ[i];
	}
	tmp[i] = ft_strjoin_triple(split[1], "=", split[2]);
	tmp[i + 1] = NULL;
	free(environ);
	environ = tmp;
}
