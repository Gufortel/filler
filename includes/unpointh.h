/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpointh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:50:46 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/14 20:52:33 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNPOINTH_H
# define UNPOINTH_H

# include "./../libft/includes/libft.h"
# define TA_MERE_LE_CHIFFRE int
# define P pt->pl

typedef struct						s_trucs
{
	char					me;
	char					adv;
	char					**tab;
	char					**pcs;
	int						x_pcs;
	int						y_pcs;
	int						x_trd;
	int						y_trd;
	int						x_tab;
	int						y_tab;
	int						x_frt;
	int						y_frt;
	TA_MERE_LE_CHIFFRE		pl;
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

/*
** check.c
*/

int									check(t_trucs **ptr, int x, int y,
									int count);
int									test_check(t_trucs **ptr, int x_pos,
									int y_pos);

/*
** solver.c
*/

void								thatsheside(t_trucs **ptr);
void								seriously_guy(t_trucs **ptr);

/*
** start.c
*/

void								start(t_trucs **ptr);
void								init(t_trucs **ptr);

#endif
