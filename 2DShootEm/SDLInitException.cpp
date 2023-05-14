#include "SDLInitException.h"

SDLInitException::SDLInitException(const char* error) 
{
	SDL_Error = std::string("Couldn't initialize SDL: ") + error;
}

const char* SDLInitException::what() const noexcept 
{
	return SDL_Error.c_str();
}