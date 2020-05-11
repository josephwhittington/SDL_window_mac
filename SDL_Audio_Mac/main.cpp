#include <iostream>

#include <SDL2/SDL.h>

#define WINDOW_HEIGHT 600
#define WINDOW_WIDTH 800

int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL Initialization failed\n";
    }
    
    SDL_Window* window = SDL_CreateWindow("Mac Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    
    bool RUNNING = true;
    while(RUNNING)
    {
        // Handle events
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
           if(event.type == SDL_QUIT)
           {
               RUNNING = false;
           } else if(event.type == SDL_KEYDOWN)
           {
               if(event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
               {
                   RUNNING = false;
               }
           }
        }
    }
    
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
