#include <iostream>

#include "SDL.h"

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
		default:
			break;
		}
	}
}