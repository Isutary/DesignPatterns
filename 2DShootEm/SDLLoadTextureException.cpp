#include "SDLLoadTextureException.h"

SDLLoadTextureException::SDLLoadTextureException(const char* error)
{
	SDL_Error = std::string("Couldn't load texture: ") + error;
}

const char* SDLLoadTextureException::what() const noexcept
{
	return SDL_Error.c_str();
}