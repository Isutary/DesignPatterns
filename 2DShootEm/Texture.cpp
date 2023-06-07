#include <SDL_image.h>

#include "Texture.h"
#include "Application.h"
#include "SDLLoadTextureException.h"

void Texture::loadTexture()
{
	std::string path = std::string("../data/texture/") + _name + ".png";

	_texture = IMG_LoadTexture(Application::getRenderer(), path.c_str());
	if (!_texture)
	{
		throw SDLLoadTextureException(SDL_GetError());
	}

	SDL_QueryTexture(_texture, NULL, NULL, &_size.w, &_size.h);
}

Texture::Texture(const char* name) : _name(name)
{
	loadTexture();
}