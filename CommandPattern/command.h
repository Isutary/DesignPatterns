#include<iostream>

#pragma once

class Command {
public:
	virtual ~Command();
	virtual void execute();
};