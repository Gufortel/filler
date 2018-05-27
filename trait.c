/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trait.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 17:57:22 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/27 18:39:21 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/unpointh.h"

int		trait(t_trucs **ptr)
{
	t_trucs					*pt;
	TA_MERE_LE_CHIFFRE		i;
	TA_MERE_LE_CHIFFRE		j;

	pt = *ptr;
	i = -1;
	while (++i < pt->x_tab)
	{
		j = -1;
		while (++j < pt->y_tab)
		{
			if (pt->tab[i][j] == pt->me)
				return (-1);
		}
	}
	return (1);
}
