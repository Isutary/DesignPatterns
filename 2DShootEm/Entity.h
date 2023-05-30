#pragma once

#include <SDL_render.h>

#include "structs.h"

class Entity {
protected:
	SDL_Point _position;
	SDL_Texture* _textrue;
	Size _size;
public:
	Entity(SDL_Point position, SDL_Texture* texture);
	SDL_Point getPosition() const;
	SDL_Texture* getTexture() const;
	Size getSize() const;
};

inline SDL_Point Entity::getPosition() const { return _position; }

inline SDL_Texture* Entity::getTexture() const { return _textrue; }

inline Size Entity::getSize() const { return _size; }