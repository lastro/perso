/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:47:24 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 20:17:24 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*res;
	char	*ret;

	if (s == NULL)
		return (NULL);
	res = (char*)malloc(ft_strlen(s));
	if (res == NULL)
		return (NULL);
	ret = res;
	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	while (*s != '\0')
	{
		*res = *s;
		res++;
		s++;
	}
	*res = '\0';
	res--;
	while (*res == ' ' || *res == '\n' || *res == '\t')
	{
		*res = '\0';
		res--;
	}
	return (ret);
}
