#include "SDL_render.h"
#include "SDL_image.h"

#include "draw.h"
#include "Application.h"
#include "SDLLoadTextureException.h"

void prepareClearScene(Color color)
{
	SDL_SetRenderDrawColor(Application::getRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderClear(Application::getRenderer());
}

void presentScene()
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

void blit(std::list<Entity*>* entities)
{
	for (auto it = entities->begin(); it != entities->end(); it++)
	{
		SDL_Rect dest{ (*it)->getPosition().x, (*it)->getPosition().y, (*it)->getSize().h, (*it)->getSize().w};

		SDL_RenderCopy(Application::getRenderer(), (*it)->getTexture(), NULL, &dest);
	}
}

void updatePositions(std::list<Moveable*>* moveables)
{
	for (auto it = moveables->begin(); it != moveables->end(); it++) (*it)->move();
}
