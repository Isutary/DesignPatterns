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

		Entity* player = new Entity(300, 300, loadTexture("sibi-default.png"));

		while (true)
		{
			prepareClearScene();
			doInput(player);
			blit(player->getTexture(), player->getX(), player->getY());
			presentScene();
			SDL_Delay(16);
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}