#include "Entity.h"

Entity::Entity(SDL_Point position, Texture* texture) : _position(position), _texture(texture) { }

Entity::~Entity() { }