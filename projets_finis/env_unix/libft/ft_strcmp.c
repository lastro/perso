/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 10:35:22 by rnicolas          #+#    #+#             */
/*   Updated: 2014/04/18 22:09:20 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_strcmp(const char *str1, const char *str2)
{
	int		i;

	i = 0;
	while (str1[i] != 0 && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
