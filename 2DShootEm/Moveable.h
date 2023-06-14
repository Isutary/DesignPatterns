#pragma once

#include "Entity.h"

class Moveable : public Entity {
protected:
	float _speed;
	void _updatePosition(SDL_FPoint position);
public:
	Moveable(SDL_FPoint position, Texture* texture, float speed);
	virtual void move() = 0;
};