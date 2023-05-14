#include <memory>

#include "../Dependencies/SDL2/include/SDL_render.h"

typedef struct SDL_Deleter {
    void operator()(SDL_Window* window) const 
    {
        SDL_DestroyWindow(window);
    }

    void operator()(SDL_Renderer* renderer) const 
    {
        SDL_DestroyRenderer(renderer);
    }
} SDL_Deleter;
    
typedef struct App {
	std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
	std::unique_ptr<SDL_Window, SDL_Deleter> window;
} App;