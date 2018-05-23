/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 00:02:46 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/23 04:58:31 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "./includes/unpointh.h"

int		main(int ac, char **av)
{
	int fd;
	char *str;
	fd = open("/dev/ttys002", O_RDWR | O_CREAT);
	while(42)
	{
		get_next_line(1, &str);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
//		write(1, "0 0\n",4);
	}
}
