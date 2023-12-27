#include "SDL.h"

#include "init.h"
#include "input.h"
#include "capFrameRate.h"
#include "SDLException.h"
#include "Application.h"
#include "Renderer.h"
#include "Enemy.h"
#include "Spawner.h"
#include <iostream>

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
			SDL_Point mouse;
			SDL_PumpEvents();
			const Uint8* keyboardState = SDL_GetKeyboardState(NULL);
			Uint32 mouseState = SDL_GetMouseState(&mouse.x, &mouse.y);
			
			renderer->updateScene();
			
			Application::getPlayer()->handleInput(keyboardState);
			Application::getPlayer()->handleInput(SDL_BUTTON(mouseState), mouse);

			if (a-- < 0)
			{
				//Spawner::CreateEnemy();
				a = 100;
			}
			capFrameRate(&then, &remainder);
			doInput();
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}