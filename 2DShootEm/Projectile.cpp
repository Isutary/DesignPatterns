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

Projectile::Projectile(SDL_Point position, Texture* texture, Direction direction, unsigned int speed) : Moveable(position, texture, speed), _direction(direction) { }

void Projectile::move()
{
	if (_boundCheck()) return;

	SDL_Point position = _position;

	switch (_direction)
	{
		case UP:
			position.y -= _speed;
			break;
		case DOWN:
			position.y += _speed;
			break;
		case LEFT:
			position.x -= _speed;
			break;
		case RIGHT:
			position.x += _speed;
			break;
		default:
			break;
	}

	_updatePosition(position);
}