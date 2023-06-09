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

void Projectile::_setSlopeAndIntercept()
{
	SDL_FPoint point1{ 0, _path(0) };
	SDL_FPoint point2{ 100, _path(100) };

	_slope = (point2.y - point1.y) / (point2.x - point1.x);
	_intercept = point1.y - _slope * point1.x;
}

float Projectile::_distance()
{
	using namespace std;

	float x = 0;
	float A = 1 + pow(_slope, 2);
	float B = 2 * _slope * _intercept - 2 * _position.x - 2 * _slope * _position.y;
	float C = pow(_position.x, 2) + pow(_intercept, 2) - 2 * _intercept * _position.y + pow(_position.y, 2) - pow(_speed, 2);
	float D = sqrt(pow(B, 2) - 4 * A * C);

	x = _direction == LEFT ? (-B - D) / (2 * A) : (-B + D) / (2 * A);

	return x;
}

Projectile::Projectile(SDL_FPoint position, Texture* texture, Path path, Direction direction) : Moveable(position, texture, PROJECTILE_SPEED), _path(path), _direction(direction)
{
	_setSlopeAndIntercept();
}

void Projectile::move()
{
	if (_boundCheck()) return;

	SDL_FPoint position = _position;

	switch (_direction)
	{
		case LEFT:
			position.x = _distance();
			position.y = _path(position.x);
			break;
		case RIGHT:
			position.x = _distance();
			position.y = _path(position.x);
			break;
		default:
			break;
	}

	_updatePosition(position);
}