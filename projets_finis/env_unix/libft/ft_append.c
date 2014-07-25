/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/18 21:53:27 by rnicolas          #+#    #+#             */
/*   Updated: 2014/05/18 22:04:53 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append(char *str, char c)
{
	char	*ret;
	int		i;

	if (!str)
	{
		ret = malloc(2);
		ret[0] = c;
		ret[1] = '\0';
		return (ret);
	}
	ret = malloc(ft_strlen(str) + 2);
	i = 0;
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = c;
	ret[i + 1] = '\0';
	free(str);
	return (ret);
}
