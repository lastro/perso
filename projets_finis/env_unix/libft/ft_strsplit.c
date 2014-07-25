/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/06 15:26:03 by rnicolas          #+#    #+#             */
/*   Updated: 2014/04/25 00:03:29 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**clean_split(char **split)
{
	int		tlen;
	char	**ret;
	int		i;

	tlen = table_len(split);
	ret = malloc(sizeof(char *) * (tlen + 1));
	i = 0;
	while (i < tlen)
	{
		ret[i] = ft_strdup(split[i]);
		i++;
	}
	ret[i] = NULL;
	free_table(split);
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tabc;
	int		i[2];

	tabc = ft_memalloc(sizeof(char *) * (ft_strlen(s) + 1));
	tabc[0] = ft_memalloc(sizeof(char) * (ft_strlen(s) + 1));
	i[0] = 0;
	i[1] = 0;
	while (*s)
	{
		if (*s != c)
		{
			tabc[i[0]][i[1]] = *s;
			i[1]++;
		}
		else if (tabc[i[0]][0])
		{
			i[1] = 0;
			i[0]++;
			tabc[i[0]] = ft_memalloc(sizeof(char) * ft_strlen(s));
		}
		else
			i[1] = 0;
		s++;
	}
	return (clean_split(tabc));
}
