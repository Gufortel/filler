/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupnext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:12:35 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/09 22:21:31 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		recupmapnext(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			i;
	int			j;
	int			x;

	x = 0;
	pt = *ptr;
	get_next_line(1, &line);
	get_next_line(1, &line);
	while (x < pt->x_tab)
	{
		get_next_line(1, &line);
		i = 4;
		j = 0;
		while (j < pt->y_tab)
		{
			pt->tab[x][j] = line[i];
			i++;
			j++;
		}
		x++;
	}
}

void		recuppiecenext(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			i;
	int			j;
	int			x;

	x = 0;
	pt = *ptr;
	get_next_line(1, &line);
	while (x < pt->x_pcs)
	{
		get_next_line(1, &line);
		i = 0;
		j = 0;
		while (j < pt->y_pcs)
		{
			pt->pcs[x][j] = line[i];
			i++;
			j++;
		}
		x++;
	}
}
