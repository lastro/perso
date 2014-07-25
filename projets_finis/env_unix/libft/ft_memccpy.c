/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:32:22 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/12 16:07:50 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*str1;
	char	*str2;

	str1 = (char*)s1;
	str2 = (char*)s2;
	while (*str2 != c && n > 0)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	if (*str2 == c && n > 0)
	{
		*str1 = *str2;
		str1++;
		return (str1);
	}
	else
		return (NULL);
}
