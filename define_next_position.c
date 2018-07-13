/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_next_position.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:43:00 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 18:57:48 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "filler.h"

int			try_next_pos(int *link, int *i, int *j, t_map *m)
{
	*link = 0;
	if ((*i + m->xp) >= m->line)
		return (-1);
	if (m->map[*i + m->xp][*j + m->yp] == '\0' ||
		(*j + m->yp) > m->col + 3)
	{
		(*i)++;
		m->memo_col = 0;
		*j = 4;
		if (*i + m->xp >= m->line)
			return (-1);
	}
	else
		(*j)++;
	m->xp = 0;
	m->yp = 0;
	return (0);
}

static int	define_dist(t_map *m, int *i, int *j, int newdist)
{
	while (m->map[m->x] != NULL)
	{
		while (m->map[m->x][m->y] != '\0')
		{
			if (m->map[m->x][m->y] == m->advers ||
				(m->map[m->x][m->y] == m->advers + 32 && m->dist == 0))
				if (newdist == 0 || ft_abs(m->x - *i - m->xpion)
					+ ft_abs(m->y - *j - m->ypion) < newdist)
					newdist = ft_abs(m->x - *i - m->xpion)
						+ ft_abs(m->y - *j - m->ypion);
			if ((m->dist == 0 && newdist != 0) ||
				(newdist != 0 && newdist <= m->dist))
			{
				m->dist = newdist;
				return (0);
			}
			(m->y)++;
		}
		m->y = 0;
		(m->x)++;
	}
	m->x = 0;
	m->y = 0;
	return (-1);
}

static void	save_possible_pos(t_map *m, int *i, int *j, int *link)
{
	if (m->pion[m->xp] != NULL || *link != 1)
		return ;
	update_updown(m, 0, 0);
	define_xypion(m, 0, 0);
	if (m->upx == 0 || ((m->pos_init == 'l' && m->upy == m->col + 3) ||
		(m->pos_init == 'r' && m->upy == 4)))
		m->stat = 1;
	if (m->downx == m->line - 1 || ((m->pos_init == 'l' &&
		m->downy == m->col + 3) || (m->pos_init == 'r' &&
		m->downy == 4)))
		m->stat = 2;
	go_updown_l(m, i, j, link);
	go_updown_r(m, i, j, link);
	if (m->posy == 0 || (m->stat == 2 && define_dist(m, i, j, 0) == 0))
	{
		m->posx = *i;
		m->posy = *j;
		try_next_pos(link, i, j, m);
	}
}

/*
** int link: nb of part of pion which touch pion on the map
*/

int			test_position_pion(t_map *m, int *i, int *j, int link)
{
	while (m->pion[m->xp] != NULL)
	{
		while (m->pion[m->xp][m->yp] != '\0')
		{
			if ((*j + m->yp) > m->col + 3)
				if (try_next_pos(&link, i, j, m) == -1)
					return (-1);
			if (m->pion[m->xp][m->yp] == '*' &&
				(m->map[*i + m->xp][*j + m->yp] == m->player
				|| m->map[*i + m->xp][*j + m->yp] == m->player + 32))
				link++;
			else if (m->pion[m->xp][m->yp] == '*' &&
				(m->map[*i + m->xp][*j + m->yp] == m->advers
				|| m->map[*i + m->xp][*j + m->yp] == m->advers + 32))
				link = 2;
			(m->yp)++;
		}
		m->yp = 0;
		(m->xp)++;
		save_possible_pos(m, i, j, &link);
		if (((m->pion[m->xp] == NULL && link == 0) || link > 1 ||
			*i + m->xp >= m->line) && (try_next_pos(&link, i, j, m) == -1))
			return (-1);
	}
	return (0);
}

void		send_position(t_map *m)
{
	m->xpion = -1;
	m->ypion = -1;
	m->distup = -1;
	m->distdown = -1;
	m->memo_line = 0;
	m->memo_col = 0;
	ft_putnbr(m->posx);
	ft_putchar(' ');
	ft_putnbr(m->posy - 4);
	ft_putchar('\n');
	ft_strdel_del(&(m->map));
	ft_strdel_del(&(m->pion));
	m->posy = 0;
}
