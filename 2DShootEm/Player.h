#pragma once

#include "SDL_events.h"

#include "Moveable.h"

class Player : public Moveable {
private:
	SDL_FPoint _newPosition;
	Path _path(SDL_FPoint player, SDL_FPoint mouse) const;
public:
	Player(SDL_FPoint position, Texture* texture);
	void move() override;
	void handleInput(SDL_KeyboardEvent* event);
	void handleInput(SDL_MouseButtonEvent* event);
	void fire(Path path, Direction direction, const char* texture);
};