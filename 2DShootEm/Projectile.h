#pragma once

#include "Moveable.h"

class Projectile : public Moveable {
private:
	Path _path;
	Direction _direction;
	float _slope;
	float _intercept;
	bool _boundCheck();
	void _setSlopeAndIntercept();
	float _distance();
public:
	Projectile(SDL_FPoint position, Texture* texture, Path path, Direction direction);
	void move() override;
};