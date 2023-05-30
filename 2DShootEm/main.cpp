#include "SDL.h"

#include "init.h"
#include "draw.h"
#include "input.h"
#include "Entity.h"
#include "SDLException.h"
#include "Application.h"

int main(int argc, char* argv[])
{
	try 
	{
		initSDL();

		Application::addPlayer(new Player(SDL_Point{ 300, 300 }, loadTexture("sibi-default.png")));

		while (true)
		{
			prepareClearScene();
			doInput(Application::getPlayer());
			blit(Application::getEntities());
			updatePositions(Application::getMoveables());
			presentScene();
			SDL_Delay(16);
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}