/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 16:57:49 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/21 20:27:34 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"
/*
int			searchtp(t_trucs **ptr, int x, int y)
{
	t_trucs						*pt;
	TA_MERE_LE_CHIFFRE			nb;

	nb = 0;
	pt = *ptr;
//	ft_printf("debut recursive\n");
	if (x >= pt->x_tab || y >= pt->y_tab || x < 0 || y < 0)
		return (2);
	if (pt->tab[x][y] == pt->adv || pt->tab[x][y] == ft_toupper(pt->adv))
		return (0);
//	if (pt->tab[x][y] == pt->adv)
//		return (200);
	nb = searchtp(ptr, x - 1, y) + 1;
	if (nb < searchtp(ptr, x, y - 1))
		nb = searchtp(ptr, x, y - 1) + 1;
//	ft_printf("fin de recursive\n");
	return (nb);
}

int			searchbt(t_trucs **ptr, int x, int y)
{
	t_trucs						*pt;
	TA_MERE_LE_CHIFFRE			nb;

	nb = 0;
	pt = *ptr;
//	ft_printf("debut recursive\n");
	if (x >= pt->x_tab || y >= pt->y_tab || x < 0 || y < 0)
		return (2);
	if (pt->tab[x][y] == pt->adv || pt->tab[x][y] == ft_toupper(pt->adv))
		return (0);
//	if (pt->tab[x][y] == pt->adv)
//		return (200);
	nb = searchbt(ptr, x + 1, y) + 1;
	if (nb < searchbt(ptr, x, y + 1))
		nb = searchbt(ptr, x, y + 1) + 1;
//	ft_printf("fin de recursive\n");
	return (nb);
}

void		thatsheside(t_trucs **ptr)
{
	TA_MERE_LE_CHIFFRE		nb;
	t_trucs					*pt;
	TA_MERE_LE_CHIFFRE		i;
	TA_MERE_LE_CHIFFRE		j;

	pt = *ptr;
	nb = -1;
	while (++nb < pt->x_tab + pt->y_tab)
	{
		i = -1;
//		ft_printf("boucle nb = %d\n", nb);
		while (++i < pt->x_tab)
		{
			j = -1;
			while (++j < pt->y_tab)
			{
				if (pt->tab[i][j] == ft_toupper(pt->me)
					&& (searchbt(ptr, i, j) == nb || searchtp(ptr, i, j) == nb)
					&& test_check(ptr, i, j) == 1)
					return ;
			}
		}
	}
	return ;
}
*/

void		seriously_guy(t_trucs **ptr)
{
	t_trucs *pt;
	int x;
	int y;

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
}
