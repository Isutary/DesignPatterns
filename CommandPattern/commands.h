#include "command.h"

#pragma once

class JumpCommand : public Command {
public:
	virtual void execute();
};

class FireCommand : public Command {
public:
	virtual void execute();
};

class WalkCommand : public Command {
public:
	virtual void execute();
};
