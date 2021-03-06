/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/23 15:27:49 by rnicolas          #+#    #+#             */
/*   Updated: 2014/01/23 15:31:22 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	table_len(char **table)
{
	size_t	i;

	i = 0;
	while (table[i])
		i++;
	return (i);
}
