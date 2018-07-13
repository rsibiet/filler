/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:43:23 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 19:13:15 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# define INIT_A NULL, NULL, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, -1
# define INIT_B -1, -1, -1, -1, -1, -1, 0, -1, 0, 0, 0

/*
**	s_map content:
**		- map: map given by VM
**		- pion: pion to place
**		- line: nb of line of map
**		- col: nb of column of map
**		- player: O || X
**		- advers: O || X (pion de adversaire)
**		- line_pion: nb of line of pion
**		- xp: position x of first part of pion in **pion
**		- yp: position y of first part of pion in **pion
**		- posx & posy: choix de la position du pion
**		- dist: distance min entre la position du pion et l'adversaire
**			--> delta(x) + delta(y)
**		- upx && upy: position du pion le plus haut a droite si P1
**			et a gauche si P2
**		- downx && downy: position du pion le plus bas a droite si P1
**			et a gauche si P2
**		- pos_init: position de mon premier pion: l = left, r = right
**		- xpion & ypion: xmin & ymin de la piece dans la map **pion
*/

typedef struct		s_map
{
	char			**map;
	char			**pion;
	char			pos_init;
	int				line;
	int				col;
	char			player;
	char			advers;
	int				line_pion;
	int				col_pion;
	int				xp;
	int				yp;
	int				posx;
	int				posy;
	int				dist;
	int				upx;
	int				upy;
	int				downx;
	int				downy;
	int				xpion;
	int				ypion;
	int				distup;
	int				distdown;
	int				stat;
	int				memo_line;
	int				memo_col;
	int				x;
	int				y;
}					t_map;

/*
** Fonctions in define_next_position.c file
*/

int					try_next_pos(int *link, int *i, int *j, t_map *m);
int					test_position_pion(t_map *m, int *i, int *j, int link);
void				send_position(t_map *m);

/*
**	Fonctions in isole_advers.c file
*/

void				define_player_position(t_map *m, int a, int b, int x);
void				define_xypion(t_map *m, int a, int b);
void				update_updown(t_map *map, int a, int b);

/*
**	Fonctions in go_to_updown.c file
*/

void				go_updown_r(t_map *m, int *i, int *j, int *link);
void				go_updown_l(t_map *m, int *i, int *j, int *link);

#endif
