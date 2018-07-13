/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsibiet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 18:44:51 by rsibiet           #+#    #+#             */
/*   Updated: 2017/02/13 19:13:34 by rsibiet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "filler.h"

static void	define_player(t_map *m)
{
	if (m->player == '1')
	{
		m->player = 'O';
		m->advers = 'X';
	}
	else if (m->player == '2')
	{
		m->player = 'X';
		m->advers = 'O';
	}
	if (m->pos_init == 0)
		define_player_position(m, 0, 0, 0);
}

static void	parse_map(t_map *m, int i, int j)
{
	define_player(m);
	while (m->map[i] != NULL)
	{
		while (m->map[i][j] != '\0')
		{
			if (m->map[i][j] == m->player)
			{
				i -= m->line_pion + 1;
				j -= m->col_pion + 1;
				if (i < 0)
					i = 0;
				if (j < 4)
					j = 4;
				test_position_pion(m, &i, &j, 0);
				m->dist = 0;
				send_position(m);
				return ;
			}
			j++;
		}
		j = 4;
		i++;
	}
}

static void	read_pion(char *line, t_map *m, char **split, int *i)
{
	m->xp = 0;
	m->yp = 0;
	if (line && line[1] == 'i')
	{
		split = ft_strsplit(line, ' ');
		m->line_pion = ft_atoi(split[1]);
		m->col_pion = ft_atoi(split[2]);
		ft_strdel_del(&split);
		if ((m->pion = (char **)malloc(sizeof(char *) *
			(m->line_pion + 1))) == NULL)
		{
			perror("Error: ");
			return ;
		}
	}
	else if (*i - m->line - 1 < m->line_pion)
		m->pion[*i - m->line - 1] = ft_strdup(line);
	m->pion[m->line_pion] = NULL;
	if (*i - m->line == m->line_pion)
	{
		parse_map(m, 0, 4);
		*i = 0;
		return ;
	}
	(*i)++;
}

static int	read_vm_data(t_map *m, int i, char **split)
{
	char	*line;
	int		r;

	while ((r = get_next_line(0, &line)) > 0)
	{
		if (m->player == 0)
			m->player = line[10];
		else if (m->map == NULL && line[3] == 't')
		{
			split = ft_strsplit(line, ' ');
			m->line = ft_atoi(split[1]);
			m->col = ft_atoi(split[2]);
			ft_strdel_del(&split);
			if ((m->map = (char **)malloc(sizeof(char *) *
				(m->line + 1))) == NULL)
				return (-1);
			m->map[m->line] = NULL;
		}
		else if (line[0] != ' ' && i < m->line)
			m->map[i++] = ft_strdup(line);
		else if (i >= m->line)
			read_pion(line, m, NULL, &i);
		ft_strdel(&line);
	}
	return (0);
}

int			main(void)
{
	t_map			*m;
	const t_map		data = (t_map){INIT_A, INIT_B};

	if ((m = ft_memdup(&data, sizeof(t_map))) == NULL)
	{
		perror("Error: ");
		return (-1);
	}
	if (read_vm_data(m, 0, NULL) == -1)
	{
		perror("Error: ");
		return (-1);
	}
	return (0);
}
