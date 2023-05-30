#include "Moveable.h"
#include "defs.h"

Moveable::Moveable(SDL_Point position, SDL_Texture* texture) : Entity(position, texture), _speed(0) { }

void Moveable::updatePosition(SDL_Point position)
{
	int minX = 0;
	int maxX = SCREEN_WIDTH - _size.w;
	int minY = 0;
	int maxY = SCREEN_HEIGHT - _size.h;

	if (position.x > 0 && position.x < maxX) _position.x = position.x;
	if (position.x < 0) _position.x = 0;
	if (position.x > maxX) _position.x = maxX;

	if (position.y > 0 && position.y < maxY) _position.y = position.y;
	if (position.y < 0) _position.y = 0;
	if (position.y > maxY) _position.y = maxY;
}