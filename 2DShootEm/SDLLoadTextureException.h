#pragma once

#include "SDLException.h"

class SDLLoadTextureException : public SDLException {
public:
	SDLLoadTextureException(const char* error);
	const char* what() const noexcept override;
};
