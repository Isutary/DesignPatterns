#pragma once

#include "SDLException.h"

class SDLInitException : public SDLException {
public:
	SDLInitException(const char* error);
	const char* what() const noexcept override;
};