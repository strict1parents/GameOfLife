#include "game_of_life.h"


bool randomINT() {
    int temp=rand()%10+1;
    return temp==1;
}

void initiBoard(struct Cell **cells) {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j) {
            cells[i][j].x=CELLLENGTH*j;
            cells[i][j].y=CELLWIDTH*i;
            cells[i][j].isAlive=randomINT();
        }
    }
}

int count(struct Cell **cells, int x, int y) {
    int count=0;
    int exes[]={-CELLLENGTH,0,CELLLENGTH,CELLLENGTH,CELLLENGTH,0,-CELLLENGTH,-CELLLENGTH};
    int eyes[]={-CELLWIDTH,-CELLWIDTH,-CELLWIDTH,0,CELLWIDTH,CELLWIDTH,CELLWIDTH,0};
    for (int i=0; i<8; ++i) {
        int newx=x+exes[i];
        int newy=y+eyes[i];
        if (((newx>=0 && newx<=(WINLENGTH-CELLLENGTH)) && (newy>=0 && newy<=(WINWIDTH-CELLWIDTH)))) {
            int row=newy/CELLWIDTH;
            int col=newx/CELLLENGTH;
            if (cells[row][col].isAlive) {
                count++;
            }
        }
    }
    return count;
}

void changevalue(struct Cell **cells) {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j) {
            if ((count(cells, cells[i][j].x, cells[i][j].y)>3 || count(cells, cells[i][j].x, cells[i][j].y)<2) && cells[i][j].isAlive==true){
                cells[i][j].isAlive=false;
            }
            if ((count(cells, cells[i][j].x, cells[i][j].y)==3 || count(cells, cells[i][j].x, cells[i][j].y)==2) && cells[i][j].isAlive==true) {
                cells[i][j].isAlive=true;
            }
            if (count(cells, cells[i][j].x, cells[i][j].y)==3 && cells[i][j].isAlive==false) {
                cells[i][j].isAlive=true;
            }
        }
    }
}

void drawBoard(struct Cell **cells, SDL_Renderer* renderer) {
    for (int i=0; i<ROWS; ++i) {
        for (int j=0; j<COLS; ++j) {
            if (cells[i][j].isAlive) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRects(renderer, &(SDL_FRect){(float)cells[i][j].x,(float)cells[i][j].y,(float)CELLLENGTH,(float)CELLWIDTH},1);
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
                SDL_RenderFillRects(renderer, &(SDL_FRect){(float)cells[i][j].x,(float)cells[i][j].y,(float)CELLLENGTH,(float)CELLWIDTH},1);
            }
        }
    }
    SDL_RenderPresent(renderer);
}
