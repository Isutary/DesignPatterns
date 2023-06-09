#include "Moveable.h"
#include "defs.h"

Moveable::Moveable(SDL_FPoint position, Texture* texture, float speed) : Entity(position, texture), _speed(speed) { }

void Moveable::_updatePosition(SDL_FPoint position)
{
	float minX = 0;
	float maxX = SCREEN_WIDTH - (float)getSize().w;
	float minY = 0;
	float maxY = SCREEN_HEIGHT - (float)getSize().h;

	if (position.x > 0 && position.x < maxX) _position.x = position.x;
	if (position.x <= 0) _position.x = 0;
	if (position.x >= maxX) _position.x = maxX;

	if (position.y > 0 && position.y < maxY) _position.y = position.y;
	if (position.y <= 0) _position.y = 0;
	if (position.y >= maxY) _position.y = maxY;
}