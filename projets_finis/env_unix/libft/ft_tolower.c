/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:34:11 by rnicolas          #+#    #+#             */
/*   Updated: 2013/11/20 11:36:52 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int n)
{
	if (n >= 65 && n <= 90)
		return (n + 32);
	return (n);
}
