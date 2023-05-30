#include "Projectile.h"

Projectile::Projectile(SDL_Point position, SDL_Texture* texture) : Moveable(position, texture) 
{ 
	_speed = 20;
}

void Projectile::move()
{
	SDL_Point position = _position;
	position.x += _speed;
	updatePosition(position);
}