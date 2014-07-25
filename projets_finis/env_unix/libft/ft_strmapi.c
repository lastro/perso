/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:50:42 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 20:18:45 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	char			*ret;
	unsigned int	n;

	if (s == NULL || f == NULL)
		return (NULL);
	res = (char*)malloc(ft_strlen(s));
	ret = res;
	if (res == NULL)
		return (NULL);
	n = 0;
	while (*s != '\0')
	{
		*res = (*f)(n, *s);
		s++;
		res++;
		n++;
	}
	*res = '\0';
	return (ret);
}
