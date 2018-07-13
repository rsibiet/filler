/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_to_updown.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:43:56 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 18:44:23 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

void	go_updown_l(t_map *m, int *i, int *j, int *link)
{
	if (m->pos_init == 'l')
	{
		if (m->stat == 0 && (m->distup == -1 || (ft_abs(*i + m->xpion)
			+ ft_abs(*j + m->ypion - m->col - 3)) <= m->distup))
		{
			m->distup =
			ft_abs(*i + m->xpion) + ft_abs(*j + m->ypion - m->col - 3);
			m->posx = *i;
			m->posy = *j;
			try_next_pos(link, i, j, m);
		}
		else if (m->stat == 1 && (m->distdown == -1 ||
			((ft_abs(*i + m->xpion - m->line + 1) <=
			m->distdown && (*i + m->xpion) >= m->memo_line) &&
			(*j + m->ypion) >= m->memo_col)))
		{
			m->memo_line = *i + m->xpion;
			m->distdown = ft_abs(*i + m->xpion - m->line + 1)
			+ ft_abs(*j + m->ypion - m->col - 3);
			m->memo_col = *j + m->ypion;
			m->posx = *i;
			m->posy = *j;
			try_next_pos(link, i, j, m);
		}
	}
}

void	go_updown_r(t_map *m, int *i, int *j, int *link)
{
	if (m->pos_init == 'r')
	{
		if (m->stat == 0 && (m->distup == -1 || (ft_abs(*i + m->xpion)
			+ ft_abs(*j + m->ypion)) <= m->distup))
		{
			m->distup =
			ft_abs(*i + m->xpion) + ft_abs(*j + m->ypion);
			m->posx = *i;
			m->posy = *j;
			try_next_pos(link, i, j, m);
		}
		else if (m->stat == 1 && (m->distdown == -1 ||
			(ft_abs(*i + m->xpion - m->line + 1) <=
			m->distdown && (*i + m->xpion) >= m->memo_line)))
		{
			m->memo_line = *i + m->xpion;
			m->distdown = ft_abs(*i + m->xpion - m->line + 1)
			+ ft_abs(*j + m->ypion - m->col - 3);
			m->posx = *i;
			m->posy = *j;
			try_next_pos(link, i, j, m);
		}
	}
}
