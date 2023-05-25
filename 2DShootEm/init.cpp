#include "SDL.h"
#include "SDL_image.h"

#include "init.h"
#include "defs.h"
#include "Application.h"
#include "SDLInitException.h"
#include "SDLCreateWindowException.h"
#include "SDLCreateRendererException.h"

void initSDL() 
{
	static bool initialized = false;
	if (initialized) return;

	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		throw SDLInitException(SDL_GetError());
	}

	SDL_Window* window = SDL_CreateWindow(SCREEN_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);
	if (!window)
	{
		throw SDLCreateWindowException(SDL_GetError());
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, rendererFlags);
	if (!renderer)
	{
		throw SDLCreateRendererException(SDL_GetError());
	}

	IMG_Init(IMG_INIT_PNG);

	Application::getInstance(window, renderer);

	initialized = true;
}