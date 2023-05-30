#include "SDL.h"

#include "input.h"

void doInput(Player* entity) 
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				entity->fire();
				break;
			case SDL_QUIT:
				SDL_Quit();
				break;
			default:
				break;
		}
	}
}