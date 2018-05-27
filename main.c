/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:46:33 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/27 21:01:55 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void		lastrecup(t_trucs **ptr)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (match(line, "*Plateau*") == 1)
		{
			ft_strdel(&line);
			recupmapnext(ptr);
			return ;
		}
	}
}

void		firstrecup(t_trucs **ptr)
{
	t_trucs		*pt;
	char		*line;

	pt = *ptr;
	while (get_next_line(0, &line))
	{
		if (match(line, "*gufortel*") == 1)
		{
			recupperso(ptr, line);
			return ;
		}
	}
}

int			main(int ac, char **av)
{
	t_trucs		*ptr;

	ptr = (struct s_trucs*)ft_memalloc(sizeof(t_trucs));
	ptr->tab = NULL;
	ptr->pcs = NULL;
	ptr->x_frt = -1;
	ptr->y_frt = 0;
	firstrecup(&ptr);
	//if (ptr->x_frt == -1)
//	ft_printf("p = %c, xtab = %d, ytab = %d, xpcs = %d, ypcs = %d ptr->x_frt = %d\n", ptr->me, ptr->x_tab, ptr->y_tab, ptr->x_pcs, ptr->y_pcs, ptr->x_frt);
	int i;
	int fd;
	fd = open("/dev/ttys003", O_WRONLY);
	while (42)
	{
		i = 0;
	//	trend(&ptr);
	//	thatsheside(&ptr);
	//	ft_printf("tendance = %d , %d\n", ptr->x_trd, ptr->y_trd);
		dprintf(fd, "x = %d, y = %d, P = %d, xpcs = %d, ypcs = %d, joeur = %c\n", ptr->x_frt,
		ptr->y_frt, ptr->pl, ptr->x_pcs, ptr->y_pcs, ptr->me);
		write(fd, "\nmap=\n", 6);
		while (i < ptr->x_tab)
		{
			write(fd, ptr->tab[i], ft_strlen(ptr->tab[i]));
			write(fd, "\n", 1);
			i++;
		}
		write(fd, "pieces=\n", 8);
		i = 0;
		while (i < ptr->x_pcs)
		{
			write(fd, ptr->pcs[i], ft_strlen(ptr->tab[i]));
			write(fd, "\n", 1);
			i++;
		}
		start(ptr, ptr->adv);
		if (trait(&ptr) == 1)
			seriously_guy(&ptr);
		lastrecup(&ptr);
		recuppiece(&ptr);
	}
}
