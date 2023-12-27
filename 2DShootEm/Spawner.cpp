#include <ctime>
#include <cstdlib>

#include "Spawner.h"
#include "defs.h"
#include "Application.h"

void Spawner::CreateEnemy()
{
	srand(time(0));

	Enemy* enemy = new Enemy(SDL_FPoint{ 0, 0 }, Application::getTexture("bibi-default"));

	Side side = (Side)(rand() % 4);
	float pixel = side == Side::TOP || side == Side::BOTTOM ? rand() % (SCREEN_WIDTH + 2 * enemy->getSize().w) : rand() % (SCREEN_HEIGHT + 2 * enemy->getSize().h);

	switch (side)
	{
		case Side::TOP:
			enemy->updatePosition(SDL_FPoint{ pixel, (float)(-enemy->getSize().h) });
			break;
		case Side::BOTTOM:
			enemy->updatePosition(SDL_FPoint{ pixel, (float)(SCREEN_HEIGHT + enemy->getSize().h) });
			break;
		case Side::LEFT:
			enemy->updatePosition(SDL_FPoint{ (float)(-enemy->getSize().w), pixel });
			break;
		case Side::RIGHT:
			enemy->updatePosition(SDL_FPoint{ (float)(SCREEN_WIDTH + enemy->getSize().w), pixel });
			break;
		default:
			break;
	}

	Application::addMoveable(enemy);
}