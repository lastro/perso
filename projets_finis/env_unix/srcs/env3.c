/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/24 15:27:53 by amusic            #+#    #+#             */
/*   Updated: 2014/04/24 15:27:54 by amusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

char	*alias_name(char *buff)
{
	char	**split;
	char	*ret;

	split = ft_strsplit(buff, '=');
	ret = ft_strdup(&split[0][6]);
	free_table(split);
	return (ret);
}

char	*alias_value(char *buff)
{
	char	**split;
	char	*ret;

	split = ft_strsplit(buff, '=');
	split[1][ft_strlen(split[1]) - 1] = 0;
	ret = ft_strdup(&split[1][1]);
	free_table(split);
	return (ret);
}
