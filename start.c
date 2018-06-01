/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:11:13 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/30 02:05:42 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		init(t_trucs *pt)
{
	if (pt->x_frt == 0)
	{
		P = 1;
		pt->y_frt = 0;
	}
	else
	{
		P = -1;
		pt->y_frt = pt->y_tab - 1;
	}
}

void		start(t_trucs *pt, char x)
{
	int			i;
	int			test;
	int			j;

	i = -1;
	test = 0;
	while (++i < pt->x_tab && test == 0)
	{
		j = -1;
		while (++j < pt->y_tab && test == 0)
		{
			if (pt->tab[i][j] == x)
			{
				if (i >= pt->x_tab / 2)
					pt->x_frt = pt->x_tab - 1;
				else
					pt->x_frt = 0;
				test++;
			}
		}
	}
	if (test == 0 && x == pt->adv)
		start(pt, ft_toupper(pt->adv));
	init(pt);
}
