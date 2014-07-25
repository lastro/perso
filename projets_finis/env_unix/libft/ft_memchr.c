/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:07:29 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 17:43:44 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	char	*s;

	s = (char*)str;
	while (0 < n)
	{
		if (*s == (char)c)
			return (s);
		s++;
		n--;
	}
	return (NULL);
}
