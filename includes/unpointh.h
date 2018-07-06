/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpointh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:50:46 by gufortel          #+#    #+#             */
/*   Updated: 2018/06/06 00:04:35 by gufortel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNPOINTH_H
# define UNPOINTH_H

# include "./../libft/includes/libft.h"
# define TA_MERE_LE_CHIFFRE int
# define PTAB pt->tab
# define PMAP pt->map
int		FD;

typedef struct						s_trucs
{
	char					me;
	char					adv;
	char					**tab;
	int						**map;
	char					**pcs;
	int						fd;
	int						b_pcs;
	int						b_pcs_x;
	int						b_pcs_y;
	int						x_pcs;
	int						y_pcs;
	int						x_tab;
	int						y_tab;
	int						x;
	int						y;
	int						first;
}									t_trucs;

/*
** fichier recup.c
*/

void								recupperso(t_trucs **ptr, char *line);
void								recupsize(t_trucs **ptr, char *line);
void								recupmap(t_trucs **ptr, char *line);
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

void								seriously_guy(t_trucs **ptr);

/*
** solver1.c
*/

void								create_tab(t_trucs *pt);
void								create_obstacle(t_trucs *pt);

/*
** check_best.c
*/

int									son_of_a_bitch(t_trucs **ptr);
void								free_map(t_trucs **ptr);

/*
** same.c
*/

int									same(t_trucs *pt, int i);
void								cpytab(t_trucs *pt);
#endif
