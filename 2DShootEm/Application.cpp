#include "Application.h"

Application::Application(SDL_Window* window, SDL_Renderer* renderer) 
{
    _window = window;
    _renderer = renderer;
}

Application* Application::getInstance(SDL_Window* window, SDL_Renderer* renderer)
{
    if (!_application) 
    {
        _application = new Application(window, renderer);
    }
    return _application;
}

SDL_Window* Application::getWindow()
{
    return _window;
}

SDL_Renderer* Application::getRenderer()
{
    return _renderer;
}