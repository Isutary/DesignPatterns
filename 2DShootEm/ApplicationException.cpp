#include "ApplicationException.h"

ApplicationException::ApplicationException()
{
	SDL_Error = std::string("Application not initialized before use");
}

const char* ApplicationException::what() const noexcept
{
	return SDL_Error.c_str();
}