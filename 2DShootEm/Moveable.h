#pragma once

#include "Entity.h"

class Moveable : public Entity {
protected:
	unsigned int _speed;
	void _updatePosition(SDL_Point position);
public:
	Moveable(SDL_Point position, Texture* texture, unsigned int speed);
	virtual void move() = 0;
};