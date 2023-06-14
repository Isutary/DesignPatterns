#pragma once

#include "Moveable.h"

class Projectile : public Moveable {
private:
	Direction _direction;
	float _theta;
	bool _boundCheck();
	SDL_FPoint _distance();
public:
	Projectile(SDL_FPoint position, Texture* texture, float theta, Direction direction);
	void move() override;
};