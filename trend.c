/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trend.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:53:57 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/11 16:51:00 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void	trend_y(t_trucs **ptr)
{
	t_trucs		*pt;
	int			i;
	int			j;
	int			count;

	pt = *ptr;
	i = 0;
	count = 0;
	while (count == 0)
	{
		j = 0;
		while (j < pt->y_pcs && count == 0)
		{
			if (pt->pcs[i][j] == '*')
				count++;
			j++;
		}
		if (count == 0)
			pt->x_trd++;
		i++;
	}
}

void		trend(t_trucs **ptr)
{
	t_trucs		*pt;
	int			i;
	int			j;
	int			count;

	pt = *ptr;
	pt->x_trd = 0;
	pt->y_trd = 0;
	j = 0;
	count = 0;
	while (count == 0)
	{
		i = 0;
		while (i < pt->x_pcs)
		{
			if (pt->pcs[i][j] == '*')
				count++;
			i++;
		}
		if (count == 0)
			pt->y_trd++;
		j++;
	}
	trend_y(ptr);
}
