/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:36:49 by amusic            #+#    #+#             */
/*   Updated: 2013/12/03 14:47:38 by amusic           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		ft_digits(int n)
{
	int	digits;

	digits = 1;
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		digits = digits * 10;
		n = n / 10;
	}
	return (digits);
}

static int		ft_digits_size(int n)
{
	int	size;

	size = 1;
	if (n < 0)
		n = -n;
	while (n / 10 > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

static char		*ft_pos_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	int		digits;

	i = 0;
	size = ft_digits_size(n);
	digits = ft_digits(n);
	if ((str = (char*)malloc(sizeof(char) * (size + 1))))
	{
		while (i < size)
		{
			str[i] = '0' + (n / digits);
			n = n % digits;
			digits = digits / 10;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	else
		return (NULL);
}

static char		*ft_neg_itoa(int n)
{
	char	*str;
	int		i;
	int		size;
	int		digits;

	i = 1;
	size = ft_digits_size(n);
	digits = ft_digits(n);
	n = -n;
	if ((str = (char*)malloc(sizeof(char) * (size + 2))))
	{
		str[0] = '-';
		while (i <= size)
		{
			str[i] = '0' + (n / digits);
			n = n % digits;
			digits = digits / 10;
			i++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}

char			*ft_itoa(int n)
{
	char	*str;

	if (n < 0)
		str = ft_neg_itoa(n);
	else
		str = ft_pos_itoa(n);
	return (str);
}
