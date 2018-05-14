/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recupnext.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 22:12:35 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/14 17:11:30 by gufortel         ###   ########.fr       */
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

	x = -1;
	pt = *ptr;
	get_next_line(1, &line);
	ft_strdel(&line);
	get_next_line(1, &line);
	ft_strdel(&line);
	while (++x < pt->x_tab)
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
		ft_strdel(&line);
	}
}

void		recuppiecefree(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			i;
	int			j;
	int			x;

	x = 0;
	pt = *ptr;
	while (x < pt->x_pcs)
	{
		ft_strdel(&pt->pcs[x]);
		x++;
	}
	free(pt->pcs);
}
