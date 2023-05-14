#pragma once

#include <exception>
#include <string>

class SDLException : public std::exception {
protected:
	std::string SDL_Error;
};