/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:46:33 by gufortel          #+#    #+#             */
/*   Updated: 2018/06/23 22:54:25 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>

int		lastrecup(t_trucs **ptr)
{
	char	*line;

	dprintf(FD, "rentrer dans lastrecup\n");
	while (get_next_line(0, &line))
	{
	dprintf(FD, "fuck\n");
		dprintf(FD, "sa affiche : %s\n", line);
		if (match(line, "*Plateau*") == 1)
		{
			ft_strdel(&line);
			recupmapnext(ptr);
			recuppiece(ptr);
			return (1);
		}
	}
	return (-1);
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

int			main(void)
{
	t_trucs		*ptr;
	int			fd;

	ptr = (struct s_trucs*)ft_memalloc(sizeof(t_trucs));
	ptr->tab = NULL;
	ptr->pcs = NULL;
	firstrecup(&ptr);
	fd = open("/dev/ttys003", O_WRONLY);
	ptr->fd = fd;
	FD = fd;
	ptr->first = 1;
	while (42)
	{
		if (ptr->first == 0)
		{
			dprintf(FD, "on rentre dans le if\n");
			free_map(&ptr);
			if (lastrecup(&ptr) == -1)
			{
				dprintf(FD, "return 1 du main \n");
				return (1);
			}
		}
// 	   /*
		int			i;
		dprintf(fd, "*********************************************************\n			NOUVELLE PIECES 				  \n*********************************************************\n");
		dprintf(fd, "xpcs = %d, ypcs = %d, xtab = %d, ytab = %d, joeur = %c, adv = %c\n",
		ptr->x_pcs, ptr->y_pcs, ptr->x_tab, ptr->y_tab, ptr->me, ptr->adv);
		write(fd, "\nmap=\n", 6);
		i = 0;
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
//		*/
		dprintf(FD, "avant create\n");
		create_tab(ptr);
		dprintf(FD, "apres create\n");
		//usleep(10000);
		ptr->first = 0;
		seriously_guy(&ptr);
		dprintf(FD, "apres seriously\n");
	}
	return (1);
}
