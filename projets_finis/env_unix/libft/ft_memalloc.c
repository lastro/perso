/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:11:10 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/12 16:06:14 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size);
	if (result)
	{
		ft_bzero(result, size);
		return (result);
	}
	return (NULL);
}
