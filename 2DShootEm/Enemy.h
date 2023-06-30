#pragma once

#include "Moveable.h"

class Enemy : public Moveable {
private:
	bool _boundCheck();
	float _getTheta(SDL_FPoint point1, SDL_FPoint point2);
	SDL_FPoint _distance();
public:
	Enemy(SDL_FPoint position, Texture* texture);
	void move() override;
};