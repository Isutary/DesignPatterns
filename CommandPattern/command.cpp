#include "command.h"

Command::~Command() {
	std::cout << "Command destructor" << std::endl;
}

void Command::execute() {
	std::cout << "Command execute" << std::endl;
}