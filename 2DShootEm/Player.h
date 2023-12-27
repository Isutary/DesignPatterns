#pragma once

#include "SDL_events.h"

#include "Moveable.h"

class Player : public Moveable {
private:
	SDL_FPoint _newPosition;
	float _getTheta(SDL_FPoint player, SDL_FPoint mouse) const;
	void _fire(SDL_FPoint mouse, const char* texture);
public:
	Player(SDL_FPoint position, Texture* texture);
	void move() override;
	void handleInput(const Uint8* state);
	void handleInput(int event, SDL_Point mouse);
};