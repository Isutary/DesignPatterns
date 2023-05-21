#include <iostream>

#include "SDL_events.h"

#include "input.h"

void doInput(void) 
{
	SDL_Event event;

	while (SDL_PollEvent(&event)) 
	{
		switch (event.type)
		{
		case SDL_QUIT:
			std::cout << "SDL_QUIT case" << std::endl;
			break;
		case SDL_KEYDOWN:
			std::cout << "SDL_KEYDOWN case" << std::endl;
			break;
		default:
			break;
		}
	}
}