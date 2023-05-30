#pragma once

#include "Entity.h"

class Moveable : public Entity {
protected:
	unsigned int _speed;
	void updatePosition(SDL_Point position);
public:
	Moveable(SDL_Point position, SDL_Texture* texture);
	virtual void move() = 0;
};