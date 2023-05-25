#pragma once

#include "SDL_render.h"

struct Entity {
	int x;
	int y;
	SDL_Texture* texture;
};

struct Color {
	Uint8 r;
	Uint8 g;
	Uint8 b;
	Uint8 a;
};