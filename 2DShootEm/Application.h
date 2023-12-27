#pragma once

#include <list>
#include <vector>

#include "SDL_render.h"
#include "Player.h"
#include "Texture.h"

class Application {
private:
    static inline Application* _application;
    static inline SDL_Window* _window;
    static inline SDL_Renderer* _renderer;
    static inline Player* _player;
    static inline std::vector<Texture*>* _textures;
    static inline std::list<Entity*>* _entities;
    static inline std::list<Moveable*>* _moveables;
    Application(SDL_Window* window, SDL_Renderer* renderer);
public:
    static Application* getInstance(SDL_Window* window = nullptr, SDL_Renderer* renderer = nullptr);
    static SDL_Window* getWindow();
    static SDL_Renderer* getRenderer();
    static Texture* getTexture(const char* texture);
    static void addPlayer(Player* player);
    static Player* getPlayer();
    static void addEntity(Entity* entity);
    static std::list<Entity*>* getEntities();
    static void addMoveable(Moveable* moveable);
    static std::list<Moveable*>* getMoveables();
    static void removeExpiredMoveables();
    static void removeEntity(Entity* entity);
};

inline Player* Application::getPlayer() { return _player; }

inline void Application::addEntity(Entity* entity) { _entities->push_back(entity); }

inline std::list<Entity*>* Application::getEntities() { return _entities; }

inline SDL_Window* Application::getWindow() { return _window; }

inline SDL_Renderer* Application::getRenderer() { return _renderer; }

inline std::list<Moveable*>* Application::getMoveables() { return _moveables; }

inline void Application::removeEntity(Entity* entity) { _entities->remove(entity); }