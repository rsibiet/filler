/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isole_advers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:44:34 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 18:49:12 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void		define_player_position(t_map *m, int a, int b, int x)
{
	int		xadvers;

	while (m->map[a] != NULL)
	{
		while (m->map[a][b] != '\0')
		{
			if (m->map[a][b] == m->player)
				x = b;
			else if (m->map[a][b] == m->advers)
				xadvers = b;
			b++;
		}
		b = 0;
		a++;
	}
	if (x < xadvers)
		m->pos_init = 'l';
	else
		m->pos_init = 'r';
}

void		define_xypion(t_map *m, int a, int b)
{
	while (m->pion[a] != NULL)
	{
		while (m->pion[a][b] != '\0')
		{
			if (m->pion[a][b] == '*')
			{
				if (m->xpion > a || m->xpion == -1)
					m->xpion = a;
				if (m->ypion > b || m->ypion == -1)
					m->ypion = b;
			}
			b++;
		}
		b = 0;
		a++;
	}
}

static void	in_update_updown(t_map *m, int a, int b)
{
	if (m->upx >= a || m->upx == -1)
	{
		m->upx = a;
		if ((m->upy < b && m->pos_init == 'l') ||
			(m->upy > b && m->pos_init == 'r') || m->upy == -1)
			m->upy = b;
	}
	if (m->downx <= a || m->downx == -1)
	{
		if ((m->downx < a && m->pos_init == 'l') ||
			(m->downx > a && m->pos_init == 'r'))
			m->downy = 4;
		m->downx = a;
		if ((m->downy < b && m->pos_init == 'l') ||
			(m->downy > b && m->pos_init == 'r') || m->downy == -1)
			m->downy = b;
	}
}

void		update_updown(t_map *m, int a, int b)
{
	while (m->map[a] != NULL)
	{
		while (m->map[a][b] != '\0')
		{
			if (m->map[a][b] == m->player || m->map[a][b] == m->player + 32)
				in_update_updown(m, a, b);
			b++;
		}
		b = 4;
		a++;
	}
}
