/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 17:54:11 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 17:55:18 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				search_score(t_piece piece, int y, int x, int **map)
{
	int			i;
	int			j;
	int			score;

	i = 0;
	score = 0;
	while (i < piece.size.y)
	{
		j = 0;
		while (j < piece.size.x)
		{
			if (piece.tab[i][j] == '*')
				score += map[y + i][x + j];
			j++;
		}
		i++;
	}
	return (score);
}

void			search_valid_position(t_gamespace g, t_piece p, int **map)
{
	int			y;
	int			x;
	int			res_x;
	int			res_y;
	int			score;

	y = -1;
	res_x = 0;
	res_y = 0;
	score = INT_MAX;
	while (++y < g.size.y)
	{
		x = -1;
		while (++x < g.size.x)
			if (is_placeable(g, p, y, x))
				if (search_score(p, y, x, map) < score)
				{
					res_x = x;
					res_y = y;
					score = search_score(p, y, x, map);
				}
	}
	print_position(res_y, res_x);
}

void			print_position(int res_y, int res_x)
{
	ft_putnbr(res_y);
	ft_putchar(' ');
	ft_putnbr(res_x);
	ft_putchar('\n');
}

void			delete_old_piece(t_piece *piece)
{
	int			i;

	i = 0;
	while (i < piece->size.y)
	{
		free(piece->tab[i]);
		i++;
	}
	ft_memdel((void **)&piece->tab);
}

void			delete_old_hitmap_table(int	**table, t_gamespace gamespace)
{
	int			i;

	i = 0;
	while (i < gamespace.size.y)
	{
		if (table[i])
			free(table[i]);
		i++;
	}
}

void			delete_old_game_table(t_gamespace *gamespace)
{
	int			i;

	i = 0;
	while (i < gamespace->size.y)
	{
		if (gamespace->tab[i])
			free(gamespace->tab[i]);
		i++;
	}
	ft_memdel((void**)&gamespace->tab);
}

int				main(void)
{
	t_gamespace		gamespace;
	t_piece			piece;
	int				**table;

	get_players_info(&gamespace);
	while (get_game_table_size(&gamespace))
	{
		skip_line();
		create_game_table(&gamespace);
		get_piece_size(&piece);
		create_piece_table(&piece);
		table = represent_int_table(gamespace);
		init_hit_map(table, gamespace);
		search_valid_position(gamespace, piece, table);
		delete_old_piece(&piece);
		delete_old_hitmap_table(table, gamespace);
		ft_memdel((void**)&table);
		delete_old_game_table(&gamespace);
	}
	return (0);
}
