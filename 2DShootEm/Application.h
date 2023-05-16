#include <memory>

#include "SDL_render.h"

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

class Application {
private:
    static std::unique_ptr<SDL_Window, SDL_Deleter> _window;
    static std::unique_ptr<SDL_Renderer, SDL_Deleter> _renderer;
public:
    static std::unique_ptr<SDL_Window, SDL_Deleter>& getWindow();
    static std::unique_ptr<SDL_Renderer, SDL_Deleter>& getRenderer();
};