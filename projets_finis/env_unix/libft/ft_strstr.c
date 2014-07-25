/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:11:25 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 18:05:36 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	c1;
	int	c2;

	if (ft_strlen(s2) == 0)
		return ((char*)s1);
	c1 = 0;
	while (s1[c1] != '\0')
	{
		c2 = 0;
		while (s1[c1 + c2] != '\0' && s1[c1 + c2] == s2[c2])
			c2++;
		if (s2[c2] == '\0')
			return ((char*)&(s1[c1]));
		c1++;
	}
	return (NULL);
}
