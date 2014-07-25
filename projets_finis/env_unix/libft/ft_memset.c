/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:22:53 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 17:34:01 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	char	*s;

	s = (char*)str;
	while (0 < n)
	{
		*(s++) = (unsigned char)c;
		n--;
	}
	return (str);
}
