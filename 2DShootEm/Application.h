#include "SDL_render.h"

class Application {
private:
    static inline Application* _application;
    static inline SDL_Window* _window;
    static inline SDL_Renderer* _renderer;
    Application(SDL_Window* window, SDL_Renderer* renderer);
public:
    static Application* getInstance(SDL_Window* window = nullptr, SDL_Renderer* renderer = nullptr);
    static SDL_Window* getWindow();
    static SDL_Renderer* getRenderer();
};