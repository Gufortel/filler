/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:50:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/11 21:26:24 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

int			check(t_trucs **ptr, int x, int y, int count)
{
	t_trucs		*pt;
	int			i;
	int			j;

	pt = *ptr;
	i = -1;
	if (x < 0 || y < 0)
		return (-1);
	while (i++ < pt->x_pcs)
	{
		j = -1;
		while (j++ < pt->y_pcs)
		{
			if (pt->pcs[i][j] == '*' && pt->tab[x + i][y + j] == 'O')
				count++;
			if (pt->pcs[i][j] == '*'
				&& (x + i > pt->x_tab || y + j > pt->y_tab))
				return (-1);
		}
	}
	if (count == 1)
		return (pose(x, y));
	return (-1);
}

int			test_check(t_trucs **ptr, int x_pos, int y_pos)
{
	t_trucs		*pt;
	int			i;
	int			j;

	pt = *ptr;
	i = x_pos - (pt->x_pcs - pt->x_trd);
	while (i < x_pos + (pt->x_pcs - pt->x_trd))
	{
		j = y_pos - (pt->y_pcs - pt->y_trd);
		while (j < y_pos + (pt->y_pcs - pt->y_trd))
		{
			if (check(ptr, i - pt->x_trd, j - pt->y_trd, 0) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (-1);
}
