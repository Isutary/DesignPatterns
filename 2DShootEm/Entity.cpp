#include "Entity.h"

Entity::Entity(SDL_FPoint position, Texture* texture) : _texture(texture) 
{ 
	_fRect = SDL_FRect{ position.x, position.y, (float)getSize().w, (float)getSize().h };
}

Entity::~Entity() { }