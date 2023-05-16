#include "Application.h"

void SDL_Deleter::operator()(SDL_Window* window) const
{
    SDL_DestroyWindow(window);
}

void SDL_Deleter::operator()(SDL_Renderer* renderer) const
{
    SDL_DestroyRenderer(renderer);
}