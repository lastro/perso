/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnicolas <rnicolas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 17:45:41 by rnicolas          #+#    #+#             */
/*   Updated: 2014/06/20 17:45:45 by rnicolas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_42sh.h>
#include <sys/types.h>
#include <libft.h>

static int		check_lex_sub2(t_lex *lex, int flag2)
{
	if (flag2 == 3)
		return (3);
	if (lex->type == 0)
		return (1);
	if (lex->type == 6 && flag2 == 2)
		return (3);
	if (lex->type == 6)
		return (0);
	if (flag2 == 1)
		return (1);
	return (2);
}

static int		check_lex_sub1(t_lex *lex, t_lex *next)
{
	if ((lex->type == 3 || lex->type == 4 || lex->type == 5) && next == NULL)
		return (1);
	if (lex->type == 4 && next->type != 2)
		return (1);
	if (lex->type == 5 && next->type != 0 && next->type != 4)
		return (1);
	if (lex->type == 4 && !ft_strcmp(lex->data, "<"))
	{
		if (access(next->data, R_OK) != -1)
			return (0);
		ft_putstr_fd("42sh: permission denied: ", 2);
		ft_putendl_fd(next->data, 2);
		return (2);
	}
	if (lex->type == 3 && next->type != 0)
		return (1);
	return (0);
}

int				check_lex(t_lex *lex)
{
	int		flag1;
	int		flag2;

	flag1 = 0;
	flag2 = 0;
	if (lex->type == 2 || lex->type == 3 || lex->type == 5)
		flag1 = 1;
	while (flag1 == 0 && lex)
	{
		flag1 = check_lex_sub1(lex, lex->next);
		flag2 = check_lex_sub2(lex, flag2);
		lex = lex->next;
	}
	if (flag1 != 0 || flag2 >= 2)
	{
		if (flag1 == 1 || flag2 >= 2)
			ft_putendl_fd("42sh : parse error", 2);
		return (1);
	}
	return (0);
}
