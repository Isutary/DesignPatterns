#pragma once

#include "Entity.h"

class Moveable : public Entity {
protected:
	float _speed;
	virtual void _updatePosition(SDL_FPoint position);
public:
	Moveable(SDL_FPoint position, Texture* texture, float speed);
	virtual void move() = 0;
	void updatePosition(SDL_FPoint position);
};