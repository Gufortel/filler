/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 15:50:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/21 17:53:08 by gufortel         ###   ########.fr       */
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
//	ft_printf("check debut x = %d, y = %d\n", x, y);
	if (x < 0 || y < 0)
	{
//		ft_printf("test check fin\n");
		return (-1);
	}
	while (++i < pt->x_pcs)
	{
		j = -1;
		while (++j < pt->y_pcs)
		{
//			ft_printf("premier if\n");
//			ft_printf(" j = %d, i = %d\npt->pcs = %c, pt->tab = %c\n", j , i, pt->pcs[i][j], pt->tab[x + i][y + j]);
			if (pt->pcs[i][j] == '*' && pt->tab[x + i][y + j] == 'O')
				count++;
//			ft_printf("deuxieme if\n");
			if (pt->pcs[i][j] == '*'
				&& (x + i > pt->x_tab || y + j > pt->y_tab))
			{
//				ft_printf("test check fin\n");
				return (-1);
			}
		}
	}
//	ft_printf("test check fin\n");
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
//	ft_printf("testcheck debut\n");
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
//	ft_printf("testckeck fin\n");
	return (-1);
}
