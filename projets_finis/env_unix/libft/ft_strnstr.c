/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:25 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/12 16:06:48 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	unsigned int	c1;
	unsigned int	c2;

	c1 = 0;
	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	while (s1[c1] != '\0' && n > c1)
	{
		c2 = 0;
		while (s1[c1 + c2] != '\0' && s1[c1 + c2] == s2[c2] && c1 + c2 < n)
			c2++;
		if (s2[c2] == '\0')
			return ((char*)&(s1[c1]));
		c1++;
	}
	return (NULL);
}
