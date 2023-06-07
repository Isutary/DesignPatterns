#pragma once

#include "Moveable.h"

class Projectile : public Moveable {
private:
	Direction _direction;
	bool _boundCheck();
public:
	Projectile(SDL_Point position, Texture* texture, Direction direction, unsigned int speed = 20);
	void move() override;
};