#pragma once

#include "Moveable.h"

class Player : public Moveable {
private:
	int a = 10;
public:
	Player(SDL_Point position, SDL_Texture* texture);
	void move() override;
	void fire();
};