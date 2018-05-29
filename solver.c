/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:57:49 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/30 00:51:39 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

int			search(t_trucs **ptr, int x, int y)
{
	t_trucs		*pt;
	int			y_t;

	pt = *ptr;
	y_t = y;
	while (x > 0 && x < pt->x_tab)
	{
		y = y_t;
		while (y > 0 && x < pt->y_tab)
		{
			if (pt->tab[x][y] == ft_toupper(pt->me))
			{
				if (test_check(ptr, x, y) == 1)
					return (1);
			}
			y = y + P;
		}
		x = x + P;
	}
	return (0);
}

int			fucking_slut(t_trucs **ptr)
{
	t_trucs		*pt;
	int			x;
	int			y;

	pt = *ptr;
	x = -1;
	while (++x > 0 && x < pt->x_tab)
	{
		y = -1;
		while (++y > 0 && y < pt->y_tab)
		{
			if (pt->tab[x][y] == pt->adv)
			{
				if (search(ptr, x, y) == 1)
					return (1);
			}
		}
	}
	return (0);
}

void		seriously_guy(t_trucs **ptr)
{
	t_trucs *pt;
	int		x;
	int		y;

	pt = *ptr;
	x = pt->x_frt;
	if (fucking_slut(ptr) == 1)
		return ;
	while (x < pt->x_tab && x >= 0)
	{
		y = pt->y_frt;
		while (y < pt->y_tab && y >= 0)
		{
			if (pt->tab[x][y] == ft_toupper(pt->me))
			{
				if (test_check(ptr, x, y) == 1)
					return ;
			}
			y = y + P;
		}
		x = x + P;
	}
	pose(0, 0);
}
