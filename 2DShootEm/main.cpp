#include <iostream>

#include "SDL.h"

#include "init.h"
#include "draw.h"
#include "input.h"
#include "SDLException.h"
using namespace std;

int main(int argc, char* argv[])
{
	try 
	{
		initSDL();

		while (true)
		{
			prepareScene();
			doInput();
			presentScene();
			SDL_Delay(16);
		}

	}
	catch (SDLException& e) {
		cout << e.what() << endl;
	}

	return 0;
}