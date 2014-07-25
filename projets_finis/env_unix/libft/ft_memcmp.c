/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:24:18 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 17:44:07 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)str1;
	s2 = (char*)str2;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (0 < n)
	{
		if (*s1 != *s2)
			return (*((unsigned char*)s1) - *((unsigned char*)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
