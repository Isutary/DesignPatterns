#include "Entity.h"

Entity::Entity(SDL_Point position, SDL_Texture* texture) : _position(position), _textrue(texture)
{
	SDL_QueryTexture(texture, NULL, NULL, &_size.h, &_size.w);
}