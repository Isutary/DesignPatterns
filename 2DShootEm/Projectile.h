#pragma once

#include "Moveable.h"

class Projectile : public Moveable {
public:
	Projectile(SDL_Point position, SDL_Texture* texture);
	void move() override;
};