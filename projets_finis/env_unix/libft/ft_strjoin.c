/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 15:44:55 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/12 16:07:16 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	char	*ret;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	result = (char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = result;
	if (result == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		*result = *s1;
		result++;
		s1++;
	}
	while (*s2 != '\0')
	{
		*result = *s2;
		result++;
		s2++;
	}
	*result = '\0';
	return (ret);
}
