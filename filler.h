/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:14:29 by ifarahi           #+#    #+#             */
/*   Updated: 2019/09/28 18:01:32 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include <limits.h>
# include "libft/libft.h"

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_position
{
	int			y;
	int			x;
}				t_position;

typedef struct	s_player
{
	char		mine;
	char		other;
}				t_player;

typedef struct	s_piece
{
	char		**tab;
	t_size		size;
}				t_piece;

typedef struct	s_gamespace
{
	char		**tab;
	t_size		size;
	t_player	players_info;
}				t_gamespace;

void			get_players_info(t_gamespace *gamespace);
int				get_game_table_size(t_gamespace *gamespace);
int				skip_line(void);
void			create_game_table(t_gamespace *gamespace);
void			get_piece_size(t_piece *piece);
void			create_piece_table(t_piece *piece);
int				is_placeable(t_gamespace g, t_piece p, int y, int x);
int				**represent_int_table(t_gamespace gamespace);
void			init_hit_map(int **table, t_gamespace gamespace);
void			flood_fill(int **tab, t_position p, int value, t_gamespace g);
void			search_valid_position(t_gamespace g, t_piece piece, int **map);
int				search_score(t_piece piece, int y, int x, int **map);
void			print_position(int res_y, int res_x);

#endif
