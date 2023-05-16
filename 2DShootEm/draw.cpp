#include "SDL.h"

#include "draw.h"
#include "Application.h"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(Application::renderer.get(), 96, 128, 255, 255);
	SDL_RenderClear(Application::renderer.get());
}

void presentScene(void)
{
	SDL_RenderPresent(Application::renderer.get());
}