#include "SDL_render.h"

#include "draw.h"
#include "Application.h"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(Application::getRenderer(), 96, 128, 255, 255);
	SDL_RenderClear(Application::getRenderer());
}

void presentScene(void)
{
	SDL_RenderPresent(Application::getRenderer());
}