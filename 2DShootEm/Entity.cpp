#include "Entity.h"
#include "defs.h"

void Entity::updateX(int x)
{
	if (_x + x >= 0 && _x + x <= SCREEN_WIDTH - _size.x) _x += x;
}

void Entity::updateY(int y)
{
	if (_y + y >= 0 && _y + y <= SCREEN_HEIGHT - _size.y) _y += y;
}

Entity::Entity(int x, int y, SDL_Texture* texture) : _x(x), _y(y), _textrue(texture) 
{
	SDL_QueryTexture(texture, NULL, NULL, &_size.x, &_size.y);
}

void Entity::move(SDL_KeyboardEvent* event)
{
	if (event->keysym.scancode == SDL_SCANCODE_UP)
	{
		updateY(-_speed);
	}

	if (event->keysym.scancode == SDL_SCANCODE_DOWN)
	{
		updateY(_speed);
	}

	if (event->keysym.scancode == SDL_SCANCODE_LEFT)
	{
		updateX(-_speed);
	}

	if (event->keysym.scancode == SDL_SCANCODE_RIGHT)
	{
		updateX(_speed);
	}
}