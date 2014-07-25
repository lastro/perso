/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:17:35 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 18:18:48 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char*)str1;
	s2 = (char*)str2;
	if (s1 <= s2)
	{
		while (0 < n)
		{
			n--;
			*s1 = *s2;
			s1++;
			s2++;
		}
		return (str1);
	}
	while (0 < n)
	{
		n--;
		s1[n] = s2[n];
	}
	return (str1);
}
