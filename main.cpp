#include <iostream>
#include <SDL.h>


const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;


bool init()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        std::cout << "SDL could not initialize! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }

    return true;
}


bool loadMedia()
{

    return true;
}


void close()
{
    SDL_Quit();
}


int main(int argc, char* argv[])
{

    if (!init())
    {
        std::cout << "Failed to initialize!" << std::endl;
        return -1;
    }


    SDL_Window* window = SDL_CreateWindow("Hero's adventure Beta", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL)
    {
        std::cout << "Failed to create window! SDL Error: " << SDL_GetError() << std::endl;
        return -1;
    }


    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL)
    {
        std::cout << "Failed to create renderer! SDL Error: " << SDL_GetError() << std::endl;
        return -1;
    }


    if (!loadMedia())
    {
        std::cout << "Failed to load media files!" << std::endl;
        return -1;
    }


    bool quit = false;
    SDL_Event e;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }


        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
        SDL_RenderClear(renderer);
        SDL_RenderPresent(renderer);
    }


    close();

    return 0;
}

