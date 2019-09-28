/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/28 18:04:58 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 18:14:26 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			get_players_info(t_gamespace *gamespace)
{
	char		*line;

	if (get_next_line(0, &line) == 1)
	{
		gamespace->players_info.mine = (line[10] == '1') ? 'o' : 'x';
		gamespace->players_info.other = (line[10] == '2') ? 'o' : 'x';
	}
}

int				get_game_table_size(t_gamespace *gamespace)
{
	char		*plateau_line;
	int			i;

	i = 8;
	if (get_next_line(0, &plateau_line) == 1)
	{
		gamespace->size.y = ft_atoi(plateau_line + 8);
		while (plateau_line[i] != ' ')
			i++;
		gamespace->size.x = ft_atoi(plateau_line + i + 1);
	}
	else
		return (0);
	return (1);
}

void			move_line_to_trash(void)
{
	char		*str;

	if (get_next_line(0, &str) == 1)
	{
		free(str);
	}
}

void			create_game_table(t_gamespace *gamespace)
{
	int			i;
	char		*line;

	i = 0;
	gamespace->tab = (char**)malloc(sizeof(char*) * gamespace->size.y);
	while (gamespace->size.y > i && get_next_line(0, &line) == 1)
	{
		gamespace->tab[i] = ft_strdup(line + 4);
		i++;
	}
}

void			get_piece_size(t_piece *piece)
{
	char		*piece_size_line;
	int			i;

	i = 6;
	if (get_next_line(0, &piece_size_line) == 1)
	{
		piece->size.y = ft_atoi(piece_size_line + 6);
		while (piece_size_line[i] != ' ')
			i++;
		piece->size.x = ft_atoi(piece_size_line + i);
	}
}
