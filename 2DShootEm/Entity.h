#pragma once

#include <SDL_rect.h>

#include "Texture.h"
#include "structs.h"

class Entity {
private:
	bool _exists = true;
protected:
	SDL_FPoint _position;
	Texture* _texture;
	void _perish();
public:
	Entity(SDL_FPoint position, Texture* texture);
	virtual ~Entity() = 0;
	bool exists() const;
	SDL_FPoint getPosition() const;
	SDL_Texture* getTexture() const;
	Size getSize() const;
};

inline void Entity::_perish() { _exists = false; }

inline bool Entity::exists() const { return _exists; }

inline SDL_FPoint Entity::getPosition() const { return _position; }

inline SDL_Texture* Entity::getTexture() const { return _texture->getTexture(); }

inline Size Entity::getSize() const { return _texture->getSize(); }