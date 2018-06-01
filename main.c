/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 14:46:33 by gufortel          #+#    #+#             */
/*   Updated: 2018/06/02 00:31:19 by gufortel         ###   ########.fr       */
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
			recuppiece(ptr);
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

int			main(void)
{
	t_trucs		*ptr;

	ptr = (struct s_trucs*)ft_memalloc(sizeof(t_trucs));
	ptr->tab = NULL;
	ptr->pcs = NULL;
	firstrecup(&ptr);
	int i;
	int fd;
	fd = open("/dev/ttys003", O_WRONLY);
	start(ptr, ptr->adv);
	while (42)
	{
		i = 0;
	//	trend(&ptr);
		create_tab(ptr);
// 	   /*
		ptr->fd = fd;
		dprintf(fd, "x = %d, y = %d, P = %d, xpcs = %d, ypcs = %d, joeur = %c, adv = %c\n",
		ptr->x_frt, ptr->y_frt, ptr->pl, ptr->x_pcs, ptr->y_pcs, ptr->me, ptr->adv);
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
//		*/
		seriously_guy(&ptr);
		lastrecup(&ptr);
		free_map(&ptr);
	}
}
