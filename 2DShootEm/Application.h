#pragma once

#include <list>

#include "SDL_render.h"
#include "Entity.h"
#include "Player.h"

class Application {
private:
    static inline Application* _application;
    static inline SDL_Window* _window;
    static inline SDL_Renderer* _renderer;
    static inline Player* _player;
    static inline std::list<Entity*>* _entities;
    static inline std::list<Moveable*>* _moveables;
    Application(SDL_Window* window, SDL_Renderer* renderer);
public:
    static Application* getInstance(SDL_Window* window = nullptr, SDL_Renderer* renderer = nullptr);
    static SDL_Window* getWindow();
    static SDL_Renderer* getRenderer();
    static void addPlayer(Player* player);
    static Player* getPlayer();
    static void addEntity(Entity* entity);
    static std::list<Entity*>* getEntities();
    static void addMoveable(Moveable* moveable);
    static std::list<Moveable*>* getMoveables();
};