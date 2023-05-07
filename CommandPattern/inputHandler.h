#include "command.h"

#pragma once

class InputHandler {
private:
	Command* buttonA;
	Command* buttonB;
	Command* buttonC;
public:
	void handleInput();
};