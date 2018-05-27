/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:53:52 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/26 21:37:47 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

/*
** Ses fonctions servent a recuperer les maps au piece tout au long
** du programme, elles sont sans leaks et test.
*/

void		recupperso(t_trucs **ptr, char *line)
{
	t_trucs		*pt;
	int			nb;

	pt = *ptr;
	nb = ft_atoi(line + 10);
	pt->me = (nb == 1) ? 'o' : 'x';
	pt->adv = (nb == 1) ? 'x' : 'o';
	ft_strdel(&line);
	while (get_next_line(0, &line))
	{
		if (match(line, "*Plateau*") == 1)
		{
			recupmap(ptr, line);
			return ;
		}
	}
}

void		recupsize(t_trucs **ptr, char *line)
{
	t_trucs		*pt;
	int			nb;
	int			i;

	pt = *ptr;
	i = 0;
	while ((line[i] >= 'a' && line[i] <= 'z')
		|| (line[i] >= 'A' && line[i] <= 'z'))
		i++;
	nb = ft_atoi(line + i);
	pt->x_tab = nb;
	while (line[i + 1] >= '0' && line[i + 1] <= '9')
		i++;
	nb = ft_atoi(line + i + 1);
	pt->y_tab = nb;
	ft_strdel(&line);
}

void		recupmap(t_trucs **ptr, char *line)
{
	t_trucs		*pt;
	int			i;
	int			j;
	int			x;

	x = -1;
	pt = *ptr;
	recupsize(ptr, line);
	get_next_line(0, &line);
	ft_strdel(&line);
	pt->tab = (char**)ft_memalloc(sizeof(char*) * pt->x_tab);
	while (++x < pt->x_tab)
	{
		get_next_line(0, &line);
		pt->tab[x] = (char*)ft_memalloc(pt->y_tab + 2);
		i = 4;
		j = -1;
		while (++j < pt->y_tab)
		{
			pt->tab[x][j] = line[i];
			i++;
		}
		ft_strdel(&line);
	}
	recuppiece(ptr);
}

void		recupsizepcs(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			nb;
	int			i;

	pt = *ptr;
	i = 0;
	get_next_line(0, &line);
	while ((line[i] >= 'a' && line[i] <= 'z')
		|| (line[i] >= 'A' && line[i] <= 'z'))
		i++;
	nb = ft_atoi(line + i);
	pt->x_pcs = nb;
	while (line[i + 1] >= '0' && line[i + 1] <= '9')
		i++;
	nb = ft_atoi(line + i + 1);
	pt->y_pcs = nb;
	ft_strdel(&line);
}

void		recuppiece(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			i;
	int			j;
	int			x;

	x = 0;
	pt = *ptr;
	recupsizepcs(ptr);
	pt->pcs = (char**)ft_memalloc(sizeof(char*) * pt->x_tab + 1);
	while (x < pt->x_pcs)
	{
		get_next_line(0, &line);
		pt->pcs[x] = (char*)ft_memalloc(pt->y_tab + 2);
		i = 0;
		j = 0;
		while (j < pt->y_pcs)
		{
			pt->pcs[x][j] = line[i];
			i++;
			j++;
		}
		x++;
		ft_strdel(&line);
	}
}
