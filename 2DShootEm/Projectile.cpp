#include <cmath>

#include "Projectile.h"
#include "defs.h"

bool Projectile::_boundCheck()
{
	int minX = 0;
	int maxX = SCREEN_WIDTH - getSize().w;
	int minY = 0;
	int maxY = SCREEN_HEIGHT - getSize().h;

	if (_position.x == minX || _position.x == maxX)
	{
		_perish();
		return true;
	}
	if (_position.y == minY || _position.y == maxY)
	{
		_perish();
		return true;
	}

	return false;
}

SDL_FPoint Projectile::_distance()
{
	SDL_FPoint point{};

	point.x = cos(_theta) * _speed;
	point.y = sin(_theta) * _speed;

	return point;
}

Projectile::Projectile(SDL_FPoint position, Texture* texture, float theta, Direction direction) : Moveable(position, texture, PROJECTILE_SPEED), _theta(theta), _direction(direction) { }

void Projectile::move()
{
	if (_boundCheck()) return;

	SDL_FPoint position = _position;

	switch (_direction)
	{
		case LEFT:
			position.x -= _distance().x;
			position.y -= _distance().y;
			break;
		case RIGHT:
			position.x += _distance().x;
			position.y += _distance().y;
			break;
		default:
			break;
	}

	_updatePosition(position);
}