/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_02.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/30 21:12:19 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/30 21:17:49 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

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

void			delete_old_hitmap_table(int **table, t_gamespace gamespace)
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
