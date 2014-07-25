/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:56:58 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 20:19:15 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*ret;

	if (s == NULL || f == NULL)
		return (NULL);
	res = (char*)malloc(ft_strlen(s));
	ret = res;
	if (res == NULL)
		return (NULL);
	while (*s != '\0')
	{
		*res = (*f)(*s);
		s++;
		res++;
	}
	*res = '\0';
	return (ret);
}
