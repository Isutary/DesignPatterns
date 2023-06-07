#pragma once

#include "SDL_render.h"

#include "structs.h"

class Texture {
private:
	const char* _name;
	SDL_Texture* _texture;
	Size _size;
	void loadTexture();
	Texture(const char* name);
public:
	const char* getName() const;
	SDL_Texture* getTexture() const;
	Size getSize() const;
	friend class Application;
};

inline const char* Texture::getName() const { return _name; }

inline SDL_Texture* Texture::getTexture() const { return _texture; }
 
inline Size Texture::getSize() const { return _size; }