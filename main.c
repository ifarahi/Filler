#include "filler.h"
#include <stdio.h>
#include <fcntl.h>

void        getPlayersInfo(t_gameSpace *gameSpace)
{
    char    *line;
    get_next_line(0, &line);
    gameSpace->playersInfo.mine = (line[10] == '1') ? 'o' : 'x';
    gameSpace->playersInfo.other = (line[10] == '2') ? 'o' : 'x';
}

void        getGameTableSize(t_gameSpace *gameSpace)
{
    char    *PlateauLine;
    int     i;

    i = 8;
    get_next_line(0, &PlateauLine);
    gameSpace->size.y = ft_atoi(PlateauLine + 8);
    while (PlateauLine[i] != ' ')
        i++;
    gameSpace->size.x = ft_atoi(PlateauLine + i + 1);
}

void        moveLineToTrash()
{
    char    *str;
    get_next_line(0, &str);
    free(str);
}

void        createGameTable(t_gameSpace *gameSpace)
{
    int     i;
    char    *line;

    i = 0;
    gameSpace->tab = (char**)malloc(sizeof(char*) * gameSpace->size.y);
    while (gameSpace->size.y > i && get_next_line(0, &line))
    {
        gameSpace->tab[i] = ft_strdup(line + 4);
        free(line);
        i++;
    }

}

void        getPieceSize(t_piece *piece)
{
    char    *pieceSizeLine;
    int     i;

    i = 6;
    get_next_line(0, &pieceSizeLine);
    piece->size.y = ft_atoi(pieceSizeLine + 6);
    while(pieceSizeLine[i] != ' ')
        i++;
    piece->size.x = ft_atoi(pieceSizeLine + i);
}

void        createPieceTable(t_piece *piece)
{
    char    *pieceLine;
    int     i;

    i = 0;
    piece->tab = (char**)malloc(sizeof(char*) * piece->size.y);
    while (i < piece->size.y)
    {
        get_next_line(0, &pieceLine);
        piece->tab[i++] = pieceLine;
    }
}

int         isPlaceable(t_gameSpace gamespace, t_piece piece, int y, int x)
{
    int     i;
    int     j;
    int     connections;

    i = 0;
    connections = 0;
    if ((piece.size.y + y) > gamespace.size.y || (piece.size.x + x) > gamespace.size.x)
        return 0;
    while (piece.size.y > i)
    {
        j = 0;
        while (piece.size.x > j)
        {
            if (ft_toupper(gamespace.tab[y + i][x + j]) == ft_toupper(gamespace.playersInfo.mine) && piece.tab[i][j] == '*')
                connections++;
            else if (gamespace.tab[y + i][x + j] != '.' && piece.tab[i][j] == '*')
                return 0;
            if (connections > 1)
                return 0;
            j++;
        }
        i++;
    }
    return ((connections == 1) ? 1 : 0);
}

int         **representIntTable(t_gameSpace gamespace)
{
    int    **gameTable;
    int    y;
    int     x;

    y = 0;
    x = 0;
    gameTable = (int**)malloc(sizeof(int*) * gamespace.size.y);
    while(y < gamespace.size.y)
    {
        gameTable[y] = (int*)malloc(sizeof(int) * gamespace.size.x);
        x = 0;
        while(x < gamespace.size.x)
        {
            if (ft_toupper(gamespace.playersInfo.mine) != ft_toupper(gamespace.tab[y][x]) && gamespace.tab[y][x] != '.')
                gameTable[y][x] = 0;
            else
                gameTable[y][x] = -1;
            x++;
        }
        y++;
    }
    return (gameTable);
}

void        floodFill(int **table, int y, int x, int value, t_gameSpace gameSpace)
{

    if (y > 0 && x > 0 && table[y - 1][x - 1] == -1)
        table[y - 1][x - 1] = value + 1;
    if (y > 0 && table[y - 1][x] == -1)
        table[y - 1][x] = value + 1;
    if (y > 0 && x < gameSpace.size.x && table[y - 1][x + 1] == -1)
        table[y - 1][x + 1] = value + 1;
    if (x > 0 && table[y][x - 1] == -1)
        table[y][x - 1] = value + 1;
    if (x < gameSpace.size.x && table[y][x + 1] == -1)
        table[y][x + 1] = value + 1;
    if (x > 0 && y < gameSpace.size.y && table[y + 1][x - 1] == -1)
        table[y + 1][x - 1] = value + 1;
    if (y < gameSpace.size.y && table[y + 1][x] == -1)
        table[y + 1][x] = value + 1;
    if (y < gameSpace.size.y && x < gameSpace.size.x && table[y + 1][x + 1] == -1)
        table[y + 1][x + 1] = value + 1;

}

void        initHitMap(int **table, t_gameSpace gameSpace, int fd)
{
    int     value;
    int     y;
    int     x;

    value = 0;
    y = 0;
    while (value < gameSpace.size.y)
    {
        dprintf(fd, "I am in \n");
        while (y < gameSpace.size.y - 1)
        {
            x = 0;
            while (x < gameSpace.size.x - 1)
            {
                if (table[y][x] == value)
                    floodFill(table, y, x, value, gameSpace);
                x++;
            }
            y++;
        }
        y = 0;
        value++;
    }

}

int         main(int argc, char **argv)
{
    t_gameSpace     gameSpace;
    t_piece         piece;
    int             i;
    int             **table;
    int             j;
    int             fd;

    j = 0;
    i = 0;
    getPlayersInfo(&gameSpace);
    getGameTableSize(&gameSpace);
    moveLineToTrash();
    createGameTable(&gameSpace);
    getPieceSize(&piece);
    createPieceTable(&piece);
    fd = open("loop", O_WRONLY);
    // dprintf(2, "my player : %c\n", gameSpace.playersInfo.mine);
    // dprintf(2, "%d\n", isPlaceable(gameSpace, piece, ft_atoi(argv[1]), ft_atoi(argv[2])));
    table = representIntTable(gameSpace);

    initHitMap(table, gameSpace, fd);

    while (i < gameSpace.size.y)
    {
        j = 0;
        while (j < gameSpace.size.x)
        {
            dprintf(2, " %d ", table[i][j]);
            j++;
        }
        dprintf(2, "\n");
        i++;
    }

    return 0;
}