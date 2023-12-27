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
    _player = nullptr;
    _textures = new std::vector<Texture*>();
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

Texture* Application::getTexture(const char* name)
{
    for (auto it = _textures->begin(); it != _textures->end(); it++)
    {
        if ((*it)->getName() == name) return *it;
    }

    Texture* texture = new Texture(name);
    _textures->push_back(texture);
    
    return texture;
}

void Application::addPlayer(Player* player)
{
    if (!_player)
    {
        _player = player;
        _entities->push_back(player);
        _moveables->push_back(player);
    }
}

void Application::addMoveable(Moveable* moveable)
{
    _moveables->push_back(moveable);
    _entities->push_back(moveable);
}

void Application::removeExpiredMoveables()
{
    for (auto it = _moveables->begin(); it != _moveables->end();)
    {
        if (!(*it)->exists())
        {
            Moveable* temp = *it;
            _entities->remove(*it);
            it = _moveables->erase(it);
            delete temp;
        }
        else it++;
    }
}