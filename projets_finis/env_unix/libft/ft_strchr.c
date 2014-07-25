/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:38:09 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 18:24:02 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strchr(const char *str, int n)
{
	char	c;

	c = (char)n;
	if (c == '\0')
	{
		while (*str != '\0')
			str++;
		return ((char*)str);
	}
	while (*str != '\0')
	{
		if (*str == c)
			return ((char*)str);
		str++;
	}
	return (NULL);
}
