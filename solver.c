/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:57:49 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/27 18:56:25 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		seriously_guy(t_trucs **ptr)
{
	t_trucs *pt;
	int		x;
	int		y;

	pt = *ptr;
	x = pt->x_frt;
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
