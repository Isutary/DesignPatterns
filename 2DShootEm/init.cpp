#include "../Dependencies/SDL2/include/SDL.h"

#include "init.h"
#include "defs.h"
#include "structs.h"
#include "SDLInitException.h"
#include "SDLCreateWindowException.h"
#include "SDLCreateRendererException.h"

void initSDL(void) 
{
	App app{};

	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;
	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) 
	{
		throw SDLInitException(SDL_GetError());
	}

	app.window = std::unique_ptr<SDL_Window, SDL_Deleter>(SDL_CreateWindow("2D Shoot 'Em", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags));
	if (!app.window)
	{
		throw SDLCreateWindowException(SDL_GetError());
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = std::unique_ptr<SDL_Renderer, SDL_Deleter>(SDL_CreateRenderer(app.window.get(), -1, rendererFlags));
	if (!app.renderer)
	{
		throw SDLCreateRendererException(SDL_GetError());
	}
}