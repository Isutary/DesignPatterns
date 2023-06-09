#include "SDL.h"

#include "input.h"

void doInput(Player* player) 
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
			case SDL_KEYDOWN:
				player->handleInput(&event.key);
				break;
			case SDL_MOUSEBUTTONDOWN:
				player->handleInput(&event.button);
				break;
			case SDL_QUIT:
				SDL_Quit();
				break;
			default:
				break;
		}
	}
}