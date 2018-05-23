/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:46:33 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/23 00:02:12 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
//	ft_printf("p = %c, xtab = %d, ytab = %d, xpcs = %d, ypcs = %d ptr->x_frt = %d\n", ptr->me, ptr->x_tab, ptr->y_tab, ptr->x_pcs, ptr->y_pcs, ptr->x_frt);
	int i;
	int fd;
	fd = open("./testvm", O_WRONLY | O_CREAT);
	while (42)
	{
		i = 0;
		trend(&ptr);
	//	thatsheside(&ptr);
//		ft_printf("tendance = %d , %d\n", ptr->x_trd, ptr->y_trd);
		while (i < ptr->x_tab)
		{
			write(1, ptr->tab[i], ft_strlen(ptr->tab[i]));
			write(1, "\n", 1);
			i++;
		}
		i = 0;
		while (i < ptr->x_pcs)
		{
			write(1, ptr->pcs[i], ft_strlen(ptr->tab[i]));
			write(1, "\n", 1);
			i++;
		}
		seriously_guy(&ptr);
		recupmapnext(&ptr);
		recuppiecefree(&ptr);
		recuppiece(&ptr);
	}
}
