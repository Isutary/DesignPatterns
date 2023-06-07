#include "SDL.h"

#include "init.h"
#include "input.h"
#include "SDLException.h"
#include "Application.h"
#include "Renderer.h"

int main(int argc, char* argv[])
{
	try 
	{
		initSDL();

		Application::addPlayer(new Player(SDL_Point{ 300, 300 }, Application::getTexture("sibi-default")));

		Renderer* renderer = new Renderer();

		while (true)
		{
			renderer->updateScene();
			doInput(Application::getPlayer());
			SDL_Delay(16);
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}