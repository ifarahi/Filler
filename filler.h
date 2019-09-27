/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ifarahi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 18:14:29 by ifarahi           #+#    #+#             */
/*   Updated: 2019/07/31 18:14:32 by ifarahi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

#include "libft/libft.h"

typedef struct  s_size
{
    int         x;
    int         y;
}               t_size;

typedef struct  s_player
{
    char        mine;
    char        other;
}               t_player;

typedef struct  s_piece
{
    char        **tab;
    t_size      size;
}               t_piece;

typedef struct  s_gameSpace
{
    char        **tab;
    t_size      size;
    t_player    playersInfo;
}               t_gameSpace;

void            getPlayersInfo(t_gameSpace *gameSpace);
void            getGameTableSize(t_gameSpace *gameSpace);
void            moveLineToTrash();
void            createGameTable(t_gameSpace *gameSpace);
void            getPieceSize(t_piece *piece);
void            createPieceTable(t_piece *piece);
int             isPlaceable(t_gameSpace gamespace, t_piece piece, int y, int x);
int             **representIntTable(t_gameSpace gamespace);

#endif