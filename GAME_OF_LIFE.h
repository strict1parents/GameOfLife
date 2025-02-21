#ifndef CONVAYSIM_GAME_OF_LIFE_H
#define CONVAYSIM_GAME_OF_LIFE_H

#include <SDL3/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define WINLENGTH 1600
#define WINWIDTH 1100
#define CELLLENGTH 5
#define CELLWIDTH 5
#define ROWS (WINWIDTH / CELLWIDTH)
#define COLS (WINLENGTH / CELLLENGTH)

#define ERR(s) do { \
    const char *Func = #s; \
    fprintf(stderr, "%s error: %s\n", Func, SDL_GetError()); \
    fprintf(stderr, "Aborting...\n"); \
    abort(); \
} while (0)

struct Cell {
    int x;
    int y;
    bool isAlive;
};

bool randomINT();
void initiBoard(struct Cell **cells);
int count(struct Cell **cells, int x, int y);
void changevalue(struct Cell **cells);
void drawBoard(struct Cell **cells, SDL_Renderer* renderer);

#endif CONVAYSIM_GAME_OF_LIFE_H