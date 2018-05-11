/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 21:53:52 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/10 17:27:42 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

void		recupperso(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			nb;

	pt = *ptr;
	get_next_line(1, &line);
	nb = ft_atoi(line + 10);
	pt->p = (nb == 1) ? 'o' : 'x';
	ft_strdel(&line);
}

void		recupsize(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			nb;
	int			i;

	pt = *ptr;
	i = 0;
	get_next_line(1, &line);
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

void		recupmap(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			i;
	int			j;
	int			x;

	x = 0;
	pt = *ptr;
	recupsize(ptr);
	get_next_line(1, &line);
	ft_strdel(&line);
	pt->tab = (char**)ft_memalloc(sizeof(char*) * pt->x_tab);
	while (x < pt->x_tab)
	{
		get_next_line(1, &line);
		pt->tab[x] = (char*)ft_memalloc(pt->y_tab + 2);
		i = 4;
		j = 0;
		while (j < pt->y_tab)
		{
			pt->tab[x][j] = line[i];
			i++;
			j++;
		}
		x++;
		ft_strdel(&line);
	}
}

void		recupsizepcs(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;
	int			nb;
	int			i;

	pt = *ptr;
	i = 0;
	get_next_line(1, &line);
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
		get_next_line(1, &line);
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

/*int			main(int ac, char **av)
{
	t_trucs		*ptr;

	ptr = (struct s_trucs*)ft_memalloc(sizeof(t_trucs));
	ptr->tab = NULL;
	ptr->pcs = NULL;
	recupperso(&ptr);
	recupmap(&ptr);
	recuppiece(&ptr);
	ft_printf("p = %c, xtab = %d, ytab = %d, xpcs = %d, ypcs = %d\n", ptr->p, ptr->x_tab, ptr->y_tab, ptr->x_pcs, ptr->y_pcs);
	int i;
	i = 0;
	while (i < ptr->x_tab)
	{
		ft_printf("tab=%s\n", ptr->tab[i]);
		i++;
	}
	i = 0;
	while (i < ptr->x_pcs)
	{
		ft_printf("pcs=%s\n", ptr->pcs[i]);
		i++;
	}
	recupmapnext(&ptr);
	recuppiecenext(&ptr);
	i = 0;
	while (i < ptr->x_tab)
	{
		ft_printf("tab=%s\n", ptr->tab[i]);
		i++;
	}
	i = 0;
	while (i < ptr->x_pcs)
	{
		ft_printf("pcs=%s\n", ptr->pcs[i]);
		i++;
	}

}*/
