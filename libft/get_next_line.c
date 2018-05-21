/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:10:45 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/21 11:22:36 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/get_next_line.h"

char	*cpystr(char *ptr, char *str)
{
	char	*tmp;
	int		size;

	size = ft_strlen(ptr);
	if (!(tmp = (char*)ft_memalloc(size + 1)))
		return (NULL);
	ft_strcpy(tmp, ptr);
	ft_strdel(&str);
	if (!(str = (char*)ft_memalloc(100)))
		return (NULL);
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	return (str);
}

int		sizestr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	int				ret;
	static char		*str[1024];
	char			buf[BUFF_SIZE + 1];

	if (fd < 0 || read(fd, buf, 0) < 0)
		return (-1);
	if (!str[fd])
		str[fd] = ft_memalloc(100);
	while (!(ft_strchr(str[fd], '\n')) && (ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		str[fd] = ft_strcat(str[fd], buf);
	}
	*line = ft_strsub(str[fd], 0, sizestr(str[fd]));
	if (ft_strchr(str[fd], '\n') != NULL)
	{
		str[fd] = cpystr(ft_strchr(str[fd], '\n') + 1, str[fd]);
		return (1);
	}
	if (sizestr(str[fd]))
	{
		str[fd] = cpystr(str[fd] + sizestr(str[fd]), str[fd]);
		return (1);
	}
	return (ret ? 1 : 0);
}
