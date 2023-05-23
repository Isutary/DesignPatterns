#include "SDL.h"

#include "init.h"
#include "draw.h"
#include "input.h"
#include "structs.h"
#include "SDLException.h"

int main(int argc, char* argv[])
{
	try 
	{
		initSDL();

		Entity player{300, 300, loadTexture("bubu.png")};

		while (true)
		{
			prepareScene();
			doInput();
			blit(player.texture, player.x, player.y);
			presentScene();
			SDL_Delay(16);
		}
	}
	catch (SDLException& e) {
		SDL_LogCritical(SDL_LOG_CATEGORY_TEST, e.what());
	}

	return 0;
}