#include "SDL.h"

#include "init.h"
#include "input.h"
#include "capFrameRate.h"
#include "SDLException.h"
#include "Application.h"
#include "Renderer.h"
#include "Enemy.h"

int main(int argc, char* argv[])
{
	try 
	{
		long then = 0;
		long remainder = 0;

		initSDL();

		Application::addPlayer(new Player(SDL_FPoint{ 300, 300 }, Application::getTexture("sibi-default")));

		Renderer* renderer = new Renderer();

		long a = 0;

		while (true)
		{
			renderer->updateScene();
			doInput(Application::getPlayer());
			if (a-- < 0)
			{
				Application::addMoveable(new Enemy(SDL_FPoint{ 500, 600 }, Application::getTexture("bibi-default")));
				a = 100;
			}
			capFrameRate(&then, &remainder);
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}