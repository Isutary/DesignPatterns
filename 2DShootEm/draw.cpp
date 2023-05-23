#include "SDL_render.h"
#include "SDL_image.h"

#include "draw.h"
#include "Application.h"
#include "SDLLoadTextureException.h"

void prepareScene(void)
{
	SDL_SetRenderDrawColor(Application::getRenderer(), 96, 128, 255, 255);
	SDL_RenderClear(Application::getRenderer());
}

void presentScene(void)
{
	SDL_RenderPresent(Application::getRenderer());
}

SDL_Texture* loadTexture(const char* filename) 
{
	std::string path = std::string("../data/texture/") + filename;

	SDL_Texture* texture = IMG_LoadTexture(Application::getRenderer(), path.c_str());
	if (!texture)
	{
		throw SDLLoadTextureException(SDL_GetError());
	}

	return texture;
}

void blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest{};
	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(Application::getRenderer(), texture, NULL, &dest);
}