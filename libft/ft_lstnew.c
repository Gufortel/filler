/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 07:05:26 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/11 07:56:58 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*p;

	p = (t_list*)malloc(sizeof(t_list));
	if (!p)
		return (NULL);
	if (!content)
	{
		p->content = NULL;
		p->content_size = 0;
		return (p);
	}
	p->content = malloc(sizeof(content));
	if (!p->content)
		return (NULL);
	ft_memcpy(p->content, content, content_size);
	p->content_size = content_size;
	p->next = NULL;
	return (p);
}
