#pragma once

#include "SDL_events.h"

#include "Moveable.h"

class Player : public Moveable {
private:
	SDL_Point _newPosition;
public:
	Player(SDL_Point position, Texture* texture);
	void move() override;
	void handleInput(SDL_KeyboardEvent* event);
	void fire(Direction direction);
};