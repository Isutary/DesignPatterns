#include "Application.h"

std::unique_ptr<SDL_Window, SDL_Deleter> Application::_window;
std::unique_ptr<SDL_Renderer, SDL_Deleter> Application::_renderer;

std::unique_ptr<SDL_Window, SDL_Deleter>& Application::getWindow()
{
	return _window;
}

std::unique_ptr<SDL_Renderer, SDL_Deleter>& Application::getRenderer()
{
	return _renderer;
}