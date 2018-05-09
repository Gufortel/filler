/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 02:16:30 by gufortel          #+#    #+#             */
/*   Updated: 2017/11/24 05:07:09 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	str = (char*)malloc(sizeof(char) * len + 1);
	i = 0;
	if (!str)
		return (str);
	while (i < len)
	{
		str[i] = s[start];
		i++;
		start++;
	}
	if (s[start] != '\0')
		str[i] = '\0';
	else
		str[i] = s[start];
	return (str);
}
