#include "Moveable.h"
#include "defs.h"

void Moveable::_updatePosition(SDL_FPoint position)
{
	float minX = 0;
	float maxX = SCREEN_WIDTH - (float)getSize().w;
	float minY = 0;
	float maxY = SCREEN_HEIGHT - (float)getSize().h;

	if (position.x > minX && position.x < maxX) _fRect.x = position.x;
	if (position.x <= minX) _fRect.x = minX;
	if (position.x >= maxX) _fRect.x = maxX;

	if (position.y > minY && position.y < maxY) _fRect.y = position.y;
	if (position.y <= minY) _fRect.y = minY;
	if (position.y >= maxY) _fRect.y = maxY;
}

Moveable::Moveable(SDL_FPoint position, Texture* texture, float speed) : Entity(position, texture), _speed(speed) { }

void Moveable::updatePosition(SDL_FPoint position)
{
	_updatePosition(position);
}