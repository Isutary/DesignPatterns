#include "SDLCreateRendererException.h"

SDLCreateRendererException::SDLCreateRendererException(const char* error)
{
	SDL_Error = std::string("Failed to create renderer: ") + error;
}

const char* SDLCreateRendererException::what() const noexcept
{
	return SDL_Error.c_str();
}