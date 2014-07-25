/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:35:22 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/01 16:47:01 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	while (0 < n)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		else if (*str1 == '\0')
			return (0);
		n--;
		str1++;
		str2++;
	}
	return (0);
}
