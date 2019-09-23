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

typedef struct  s_gameSpace{
    char        **tab;
    t_size      size;
}               t_gameSpace;


void            getPlayersInfo(t_player *players);

#endif