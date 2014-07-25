/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 16:51:37 by rnicolas          #+#    #+#             */
/*   Updated: 2013/12/12 16:09:04 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	count;

	if (s == NULL || f == NULL)
		return ;
	count = 0;
	while (*s != '\0')
	{
		(*f)(count, s);
		s++;
		count++;
	}
}
