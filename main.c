#include "filler.h"
#include <stdio.h>

void        getPlayersInfo(t_player *players)
{
    char    *firstLine;

    if (get_next_line(0, &firstLine)){
        players->mine = (firstLine[10] == '1') ? 'o' : 'x';
        players->other = (firstLine[10] == '2') ? 'o' : 'x';
    }
}

void        getGameTableSize(t_gameSpace *gameSpace)
{
    char    *PlateauLine;
    int     fd;
    int     i;
    int     lenght;

    i = 8;
    lenght = 0;
    fd = open("output", O_WRONLY);
    get_next_line(0, &PlateauLine);
    while (ft_isalnum(PlateauLine[i++]))
        lenght++;
    ft_putendl_fd(PlateauLine, fd);
    gameSpace->size.y = ft_atoi(ft_strsub(PlateauLine,8,3));
    gameSpace->size.x = ft_atoi(ft_strsub(PlateauLine,11,3));

}

int         main()
{
    int             fd;
    t_player        players;
    char            *str;
    t_gameSpace     gameSpace;

    // fd = open("output", O_WRONLY);
    // while (get_next_line(0, &str))
    // {
        //ft_putendl_fd(str, fd);
    getPlayersInfo(&players);
    getGameTableSize(&gameSpace);
    dprintf(2,"%d || %d\n", gameSpace.size.y, gameSpace.size.x);
    // }
    
    return 0;
}