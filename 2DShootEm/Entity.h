#pragma once

#include <SDL_render.h>
#include <SDL_events.h>

class Entity {
private:
	int _x;
	int _y;
	SDL_Texture* _textrue;
	int _speed = 20;
	SDL_Point _size;
	void updateX(int x);
	void updateY(int y);
public:
	Entity(int x, int y, SDL_Texture* texture);
	int getX() const;
	int getY() const;
	SDL_Texture* getTexture() const;
	void move(SDL_KeyboardEvent* event);
};

inline int Entity::getX() const { return _x; }

inline int Entity::getY() const { return _y; }

inline SDL_Texture* Entity::getTexture() const { return _textrue; }