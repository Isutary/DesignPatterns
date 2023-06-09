#pragma once

#include <functional>

#include "Entity.h"

class Moveable : public Entity {
protected:
	using Path = std::function<float(float)>;
	float _speed;
	void _updatePosition(SDL_FPoint position);
public:
	Moveable(SDL_FPoint position, Texture* texture, float speed);
	virtual void move() = 0;
};