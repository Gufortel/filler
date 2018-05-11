/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpointh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:50:46 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/11 21:06:37 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNPOINTH_H
# define UNPOINTH_H

# include "./../libft/includes/libft.h"

typedef struct						s_trucs
{
	char					p;
	char					**tab;
	char					**pcs;
	int						x_pcs;
	int						y_pcs;
	int						x_trd;
	int						y_trd;
	int						x_tab;
	int						y_tab;
}									t_trucs;

/*
** fichier recup.c
*/

void								recupperso(t_trucs **ptr);
void								recupsize(t_trucs **ptr);
void								recupmap(t_trucs **ptr);
void								recupsizepcs(t_trucs **ptr);
void								recuppiece(t_trucs **ptr);

/*
** recupnext.c
*/

void								recupmapnext(t_trucs **ptr);
void								recuppiecefree(t_trucs **ptr);

/*
** trend.c
*/

void								trend(t_trucs **ptr);

/*
** pose.c
*/

int									pose(int x, int y);

#endif
