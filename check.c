/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:50:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/28 16:00:50 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

/*
** fonction qui check si une piece peut rentrer a la position x/y
** si oui elle la pose.
*/

int			check(t_trucs **ptr, int x, int y, int count)
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
		return (pose(x, y));
	return (-1);
}

/*
** fonction qui cherche a poser un piece autour de la position x/y
*/

int			test_check(t_trucs **ptr, int x_pos, int y_pos)
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
			if (check(ptr, i, j, 0) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (-1);
}
