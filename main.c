#include "game_of_life.h"



int main() {
    srand(time(NULL));
    int running = 1;
    struct Cell** cells = malloc(ROWS * sizeof(struct Cell*));
    atexit(SDL_Quit);
    for (int i=0; i<ROWS; i++) {
        cells[i] = malloc(COLS * sizeof(struct Cell));
        if (cells[i] == NULL) {
            ERR(*Memory Allocation Failed ..exit..*);
        }
    }
    if(cells==NULL) {
        ERR(*Memory Allocation Error ..exit..*);
    }

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        ERR(SDL_Init());

    }

    SDL_Window* window = SDL_CreateWindow(
            "GameOfLife",// Заголовок окна
            WINLENGTH,     // Ширина окна
            WINWIDTH,      // Высота окна
            SDL_WINDOW_OPENGL
            );
    if (window == NULL) {
        ERR(SDL_CreateWindow());
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL) {
        ERR(SDL_CreateRenderer());
    }

    initiBoard(cells);

    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                for (int i = 0; i < ROWS; i++) {
                    free(cells[i]);
                }
                free(cells);
                cells = NULL;
                running = 0;
            }
        }
        drawBoard(cells, renderer);
        changevalue(cells);
        SDL_Delay(100);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    return 0;
}