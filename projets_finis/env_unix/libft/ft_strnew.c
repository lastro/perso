/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:35:30 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 20:21:09 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	size_t	count;

	count = 0;
	res = (char*)malloc(size);
	if (res == NULL)
		return (NULL);
	while (count <= size)
	{
		res[count] = '\0';
		count++;
	}
	return (res);
}
