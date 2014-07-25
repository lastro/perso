/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:38:09 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/30 18:24:46 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = ft_strlen(str);
	if (c == 0)
	{
		count = ft_strlen(str);
		return ((char*)&(str[count]));
	}
	while (str[count] != (char)c && count >= 0)
		count--;
	if (count == -1)
		return (0);
	else
		return ((char*)&(str[count]));
}
