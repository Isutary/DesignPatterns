#pragma once

#include "SDLException.h"

class ApplicationException : public SDLException {
public:
	ApplicationException();
	const char* what() const noexcept override;
};
