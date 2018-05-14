/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:46:33 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/14 20:52:24 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

int			main(int ac, char **av)
{
	t_trucs		*ptr;

	ptr = (struct s_trucs*)ft_memalloc(sizeof(t_trucs));
	ptr->tab = NULL;
	ptr->pcs = NULL;
	ptr->x_frt = -1;
	ptr->y_frt = 0;
	recupperso(&ptr);
	recupmap(&ptr);
	recuppiece(&ptr);
	if (ptr->x_frt == -1)
		start(&ptr);
	ft_printf("p = %c, xtab = %d, ytab = %d, xpcs = %d, ypcs = %d ptr->x_frt = %d\n", ptr->me, ptr->x_tab, ptr->y_tab, ptr->x_pcs, ptr->y_pcs, ptr->x_frt);
	int i;

	while (42)
	{
		i = 0;
		trend(&ptr);
	//	thatsheside(&ptr);
		seriously_guy(&ptr);
		ft_printf("tendance = %d , %d\n", ptr->x_trd, ptr->y_trd);
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
		recuppiecefree(&ptr);
		recuppiece(&ptr);
	}
}
