#include "SDL.h"

#include "input.h"

void doInput(Entity* entity) 
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				entity->move(&event.key);
				break;
			case SDL_QUIT:
				SDL_Quit();
				break;
			default:
				break;
		}
	}
}