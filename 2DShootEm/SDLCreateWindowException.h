#pragma once

#include "SDLException.h"

class SDLCreateWindowException : public SDLException {
public:
	SDLCreateWindowException(const char* error);
	const char* what() const noexcept override;
};