#include "Entity.h"

Entity::Entity(SDL_FPoint position, Texture* texture) : _position(position), _texture(texture) { }

Entity::~Entity() { }