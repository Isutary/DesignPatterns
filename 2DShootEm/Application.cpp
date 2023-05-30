#include "Application.h"
#include "ApplicationException.h"

Application::Application(SDL_Window* window, SDL_Renderer* renderer) 
{
    if (!window && !renderer)
    { 
        throw ApplicationException();
    }

    _window = window;
    _renderer = renderer;
    _entities = new std::list<Entity*>();
    _moveables = new std::list<Moveable*>();
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

void Application::addPlayer(Player* player)
{
    _player = player;
    _moveables->push_back(player);
    _entities->push_back(player);
}

Player* Application::getPlayer()
{
    return _player;
}

void Application::addEntity(Entity* entity)
{
    _entities->push_back(entity);
}

std::list<Entity*>* Application::getEntities()
{
    return _entities;
}

void Application::addMoveable(Moveable* moveable)
{
    _moveables->push_back(moveable);
    _entities->push_back(moveable);
}

std::list<Moveable*>* Application::getMoveables()
{
    return _moveables;
}
