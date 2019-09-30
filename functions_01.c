/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:04:51 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 18:17:18 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			create_piece_table(t_piece *piece)
{
	char		*piece_line;
	int			i;

	i = 0;
	piece->tab = (char**)malloc(sizeof(char*) * piece->size.y);
	while (i < piece->size.y)
	{
		get_next_line(0, &piece_line);
		piece->tab[i++] = piece_line;
	}
}

int				is_placeable(t_gamespace g, t_piece p, int y, int x)
{
	int			i;
	int			j;
	int			connections;

	i = -1;
	connections = 0;
	if ((p.size.y + y) > g.size.y
			|| (p.size.x + x) > g.size.x)
		return (0);
	while (p.size.y > ++i)
	{
		j = -1;
		while (p.size.x > ++j)
		{
			if (ft_toupper(g.tab[y + i][x + j])
					== ft_toupper(g.players_info.mine)
					&& p.tab[i][j] == '*')
				connections++;
			else if (g.tab[y + i][x + j] != '.' && p.tab[i][j] == '*')
				return (0);
			if (connections > 1)
				return (0);
		}
	}
	return ((connections == 1) ? 1 : 0);
}

int				**represent_int_table(t_gamespace g)
{
	int			**tab;
	int			y;
	int			x;

	y = 0;
	x = 0;
	if ((tab = (int**)malloc(sizeof(int*) * g.size.y)))
	{
		while (y < g.size.y)
		{
			tab[y] = (int*)malloc(sizeof(int) * g.size.x);
			x = 0;
			while (x < g.size.x)
			{
				if (g.players_info.mine && ft_toupper(g.players_info.mine)
						!= ft_toupper(g.tab[y][x]) && g.tab[y][x] != '.')
					tab[y][x] = 0;
				else
					tab[y][x] = -1;
				x++;
			}
			y++;
		}
	}
	return (tab);
}

void			flood_fill(int **tab, t_position p, int value, t_gamespace g)
{
	if (p.y > 0 && p.x > 0 && tab[p.y - 1][p.x - 1] == -1)
		tab[p.y - 1][p.x - 1] = value + 1;
	if (p.y > 0 && tab[p.y - 1][p.x] == -1)
		tab[p.y - 1][p.x] = value + 1;
	if (p.y > 0 && (p.x + 1) < g.size.x && tab[p.y - 1][p.x + 1] == -1)
		tab[p.y - 1][p.x + 1] = value + 1;
	if (p.x > 0 && tab[p.y][p.x - 1] == -1)
		tab[p.y][p.x - 1] = value + 1;
	if ((p.x + 1) < g.size.x && tab[p.y][p.x + 1] == -1)
		tab[p.y][p.x + 1] = value + 1;
	if (p.x > 0 && (p.y + 1) < g.size.y && tab[p.y + 1][p.x - 1] == -1)
		tab[p.y + 1][p.x - 1] = value + 1;
	if ((p.y + 1) < g.size.y && tab[p.y + 1][p.x] == -1)
		tab[p.y + 1][p.x] = value + 1;
	if ((p.y + 1) < g.size.y && (p.x + 1)
			< g.size.x && tab[p.y + 1][p.x + 1] == -1)
		tab[p.y + 1][p.x + 1] = value + 1;
}

void			init_hit_map(int **table, t_gamespace gamespace)
{
	int				value;
	t_position		position;

	value = 0;
	position.y = 0;
	while (value < gamespace.size.y || value < gamespace.size.x)
	{
		position.y = 0;
		while (position.y < gamespace.size.y)
		{
			position.x = 0;
			while (position.x < gamespace.size.x)
			{
				if (table[position.y][position.x] == value)
					flood_fill(table, position, value, gamespace);
				position.x++;
			}
			position.y++;
		}
		value++;
	}
}
