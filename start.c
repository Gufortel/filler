/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:11:13 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/14 20:08:11 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		init(t_trucs **ptr)
{
	t_trucs *pt;

	pt = *ptr;
	if (pt->x_frt == 0)
		P = 1;
	else
		P = -1;
}

void		start(t_trucs **ptr)
{
	t_trucs		*pt;
	int			i;
	int			j;

	pt = *ptr;
	i = -1;
	while (++i < pt->x_tab)
	{
		j = -1;
		while (++j < pt->y_tab)
		{
			if (pt->tab[i][j] == ft_toupper(pt->adv))
			{
				if (i > pt->x_tab / 2)
				{
					pt->x_frt = pt->x_tab - 1;
					pt->y_frt = pt->y_tab - 1;
				}
				else
					pt->x_frt = 0;
			}
		}
	}
	init(ptr);
}

