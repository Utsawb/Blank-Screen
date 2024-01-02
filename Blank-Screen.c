#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_GAMECONTROLLER) < 0)
    {
        fprintf(stderr, "Failed to initialize SDL\n");
        return EXIT_FAILURE;
    }

    SDL_Window *window = SDL_CreateWindow("Blank Screen", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 0, 0,
                                          SDL_WINDOW_FULLSCREEN_DESKTOP);

    if (!window)
    {
        fprintf(stderr, "Failed to create window\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_Event event;
    int quit = 0;
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
                case SDL_CONTROLLERBUTTONDOWN:
                case SDL_KEYDOWN:
                case SDL_QUIT:
                    quit = 1;
                    break;
            }
        }

        SDL_Delay(100);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
