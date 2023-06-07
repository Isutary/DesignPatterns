#include "Moveable.h"
#include "defs.h"

Moveable::Moveable(SDL_Point position, Texture* texture, unsigned int speed) : Entity(position, texture), _speed(speed) { }

void Moveable::_updatePosition(SDL_Point position)
{
	int minX = 0;
	int maxX = SCREEN_WIDTH - getSize().w;
	int minY = 0;
	int maxY = SCREEN_HEIGHT - getSize().h;

	if (position.x > 0 && position.x < maxX) _position.x = position.x;
	if (position.x <= 0) _position.x = 0;
	if (position.x >= maxX) _position.x = maxX;

	if (position.y > 0 && position.y < maxY) _position.y = position.y;
	if (position.y <= 0) _position.y = 0;
	if (position.y >= maxY) _position.y = maxY;
}