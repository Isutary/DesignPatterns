#include "SDLCreateWindowException.h"
#include "defs.h"

SDLCreateWindowException::SDLCreateWindowException(const char* error)
{
	SDL_Error = "Failed to open " + std::to_string(SCREEN_WIDTH) + " x " + std::to_string(SCREEN_HEIGHT) + " window: " + error;
}

const char* SDLCreateWindowException::what() const noexcept
{
	return SDL_Error.c_str();
}