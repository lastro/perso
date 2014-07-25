/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:44:03 by rnicolas          #+#    #+#             */
/*   Updated: 2014/05/28 17:10:27 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ret;
	int		i;
	int		len;

	len = ft_strlen(str) + 1;
	ret = (char *)malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	return (ret);
}
