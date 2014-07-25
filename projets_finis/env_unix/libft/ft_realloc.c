/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/28 21:47:45 by rnicolas          #+#    #+#             */
/*   Updated: 2014/01/18 16:37:14 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*p;

	p = malloc(size);
	if (ptr && p)
	{
		p = ft_memcpy(p, ptr, size);
		free(ptr);
	}
	return (p);
}
