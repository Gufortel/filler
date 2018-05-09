/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unpointh.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gufortel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 17:50:46 by gufortel          #+#    #+#             */
/*   Updated: 2018/05/09 22:15:24 by gufortel         ###   ########.fr       */
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
void								recuppiecenext(t_trucs **ptr);

/*
** ...
*/

#endif
