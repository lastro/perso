/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 11:01:17 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 17:37:18 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, void const *src, size_t n)
{
	char	*d;
	char	*s;

	d = (char*)dest;
	s = (char*)src;
	while (0 < n)
	{
		*d = *s;
		n--;
		d++;
		s++;
	}
	return (dest);
}
