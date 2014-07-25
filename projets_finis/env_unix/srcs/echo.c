/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusic <amusic@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/22 12:20:22 by amusic            #+#    #+#             */
/*   Updated: 2014/06/20 15:20:29 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <libft.h>

int		ft_echo(char **split)
{
	int	i;

	i = 1;
	while (split[i] != 0)
	{
		ft_putstr(split[i]);
		if (split[i + 1] != 0)
			ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	return (0);
}
