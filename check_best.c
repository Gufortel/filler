/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_best.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 22:55:26 by gufortel          #+#    #+#             */
/*   Updated: 2018/06/03 19:09:00 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

int			check_best(t_trucs *pt, int x, int y)
{
	int		i;
	int		j;
	int		count;

	count = 0;
	i = -1;
	while (++i < pt->x_pcs)
	{
		j = -1;
		while (++j < pt->y_pcs)
		{
			if (i + x >= 0 && i + x < pt->x_tab &&
				j + y >= 0 && j + y < pt->y_tab)
				count = count + PMAP[i + x][j + y];
		}
	}
	if (count < pt->b_pcs)
	{
		pt->b_pcs = count;
		pt->b_pcs_x = x;
		pt->b_pcs_y = y;
	}
	return (1);
}

/*
** fonction qui check si une piece peut rentrer a la position x/y
** si oui elle la pose.
*/

int			check_pcs(t_trucs **ptr, int x, int y, int count)
{
	t_trucs		*pt;
	int			i;
	int			j;

	pt = *ptr;
	i = -1;
	while (++i < pt->x_pcs)
	{
		j = -1;
		while (++j < pt->y_pcs)
		{
			if ((pt->pcs[i][j] == '*' && (x + i < 0 || y + j < 0)))
				return (-1);
			if (pt->pcs[i][j] == '*' && ((x + i >= pt->x_tab ||
				y + j >= pt->y_tab) || pt->tab[x + i][y + j] ==
				ft_toupper(pt->adv) || pt->tab[x + i][y + j] == pt->adv))
				return (-1);
			if ((pt->pcs[i][j] == '*' && (pt->tab[x + i][y + j] ==
				ft_toupper(pt->me) || pt->tab[x + i][y + j] == pt->me)))
				count++;
		}
	}
	if (count == 1)
		check_best(pt, x, y);
	return (1);
}

/*
** fonction qui cherche a poser un piece autour de la position x/y
*/

int			test_check_pcs(t_trucs **ptr, int x_pos, int y_pos)
{
	t_trucs		*pt;
	int			i;
	int			j;

	pt = *ptr;
	i = x_pos - (pt->x_pcs);
	while (i < x_pos + (pt->x_pcs))
	{
		j = y_pos - (pt->y_pcs);
		while (j < y_pos + (pt->y_pcs))
		{
			check_pcs(ptr, i, j, 0);
			j++;
		}
		i++;
	}
	return (-1);
}

void		free_map(t_trucs **ptr)
{
	t_trucs		*pt;
	int			i;

	i = -1;
	pt = *ptr;
	while (++i < pt->x_tab)
	{
		free(PMAP[i]);
	}
	free(PMAP);
	PMAP = NULL;
}

int			son_of_a_bitch(t_trucs **ptr)
{
	int		i;
	int		j;
	t_trucs *pt;

	i = -1;
	pt = *ptr;
	pt->b_pcs = 10000;
	while (++i < pt->x_tab)
	{
		j = -1;
		while (++j < pt->y_tab)
		{
			if (pt->tab[i][j] == ft_toupper(pt->me))
				test_check_pcs(ptr, i, j);
		}
	}
	dprintf(pt->fd, "best pieces is %d %d", pt->b_pcs_x, pt->b_pcs_y);
	return (1);
}
