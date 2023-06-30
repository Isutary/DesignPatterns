#include "collisionDetector.h"

bool collisionDetector(const SDL_FRect* fRect1, const SDL_FRect* fRect2)
{
	SDL_FRect a{};

	return SDL_IntersectFRect(fRect1, fRect2, &a);
}