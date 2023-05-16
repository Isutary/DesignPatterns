#include <memory>

#include "SDL_render.h"

typedef struct SDL_Deleter {
    void operator()(SDL_Window* window) const;
    void operator()(SDL_Renderer* renderer) const;
} SDL_Deleter;

typedef struct Application {
    static inline std::unique_ptr<SDL_Window, SDL_Deleter> window;
    static inline std::unique_ptr<SDL_Renderer, SDL_Deleter> renderer;
} Application;