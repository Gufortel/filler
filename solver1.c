/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 21:30:36 by gufortel          #+#    #+#             */
/*   Updated: 2018/06/03 19:09:39 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		write_pt(t_trucs *pt, int i, int j, int y)
{
	if (j - 1 >= 0)
		PMAP[i][j - 1] = (PMAP[i][j - 1] == 0) ? y : PMAP[i][j - 1];
	if (j + 1 < pt->y_tab)
		PMAP[i][j + 1] = (PMAP[i][j + 1] == 0) ? y : PMAP[i][j + 1];
	if (i - 1 >= 0)
		PMAP[i - 1][j] = (PMAP[i - 1][j] == 0) ? y : PMAP[i - 1][j];
	if (i + 1 < pt->x_tab)
		PMAP[i + 1][j] = (PMAP[i + 1][j] == 0) ? y : PMAP[i + 1][j];
}

void		feed_tab(t_trucs *pt, int y)
{
	int		i;
	int		j;

	i = -1;
	while (++i < pt->x_tab)
	{
		j = -1;
		while (++j < pt->y_tab)
		{
			if (PMAP[i][j] == 0)
				PMAP[i][j] = y + 2;
		}
	}
}

void		create_number(t_trucs *pt)
{
	TA_MERE_LE_CHIFFRE		i;
	TA_MERE_LE_CHIFFRE		j;
	TA_MERE_LE_CHIFFRE		x;
	TA_MERE_LE_CHIFFRE		y;

	x = -1;
	y = 0;
	while (++y < pt->y_tab + pt->x_tab)
	{
		i = -1;
		while (++i < pt->x_tab)
		{
			j = -1;
			while (++j < pt->y_tab)
			{
				if (pt->map[i][j] == x)
					write_pt(pt, i, j, y);
			}
		}
		x = (x == -1) ? 1 : x + 1;
	}
	feed_tab(pt, y);
	i = -1;
	dprintf(pt->fd, "   ");
	while (++i < pt->y_tab)
		dprintf(pt->fd, "%2d", i);
	i = -1;
	dprintf(pt->fd, "\n");
	while (++i < pt->x_tab)
	{
		j = -1;
		dprintf(pt->fd, "%2d ", i);
		while (++j < pt->y_tab)
			dprintf(pt->fd, "%2d", pt->map[i][j]);
		dprintf(pt->fd, "\n");
	}
}

void		create_obstacle(t_trucs *pt)
{
	TA_MERE_LE_CHIFFRE		i;
	TA_MERE_LE_CHIFFRE		j;

	i = -1;
	while (++i < pt->x_tab)
	{
		j = -1;
		while (++j < pt->y_tab)
		{
			if (PTAB[i][j] == ft_toupper(pt->adv) || PTAB[i][j] == pt->adv)
				pt->map[i][j] = -1;
			if (PTAB[i][j] == ft_toupper(pt->me) || PTAB[i][j] == pt->me)
				pt->map[i][j] = -2;
		}
	}
	create_number(pt);
}

void		create_tab(t_trucs *pt)
{
	int			**tab;
	int			i;

	i = 0;
	tab = (int**)ft_memalloc(sizeof(int*) * pt->x_tab + 1);
	while (i < pt->x_tab)
	{
		tab[i] = (int*)ft_memalloc(sizeof(int) * pt->y_tab + 1);
		i++;
	}
	tab[i] = NULL;
	pt->map = tab;
	dprintf(pt->fd, "test\n");
	create_obstacle(pt);
}
