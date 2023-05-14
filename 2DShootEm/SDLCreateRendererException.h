#pragma once

#include "SDLException.h"

class SDLCreateRendererException : public SDLException {
public:
	SDLCreateRendererException(const char* error);
	const char* what() const noexcept override;
};