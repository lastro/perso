/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:34:54 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 18:20:20 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *str1, const char *str2, size_t n)
{
	unsigned int	size;
	unsigned int	ret;

	if (ft_strlen(str1) < n)
		ret = ft_strlen(str1) + ft_strlen(str2);
	else
		ret = n + ft_strlen(str2);
	size = ft_strlen(str1);
	while (size + 1 < n)
	{
		str1[size] = *str2;
		str2++;
		size++;
	}
	str1[size] = '\0';
	return (ret);
}
