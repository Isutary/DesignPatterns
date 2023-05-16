#include <iostream>

#include "SDL.h"

#include "init.h"
#include "SDLException.h"
using namespace std;

int main(int argc, char* argv[])
{
	try {
		initSDL();
	}
	catch (SDLException& e) {
		cout << e.what() << endl;
	}

	return 0;
}