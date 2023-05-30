#pragma once

#include <list>

#include "SDL_render.h"

#include "structs.h"
#include "Entity.h"
#include "Moveable.h"

void prepareClearScene(Color color = Color{ 96, 155, 203, 255 });
void presentScene();
SDL_Texture* loadTexture(const char* filename);
void blit(std::list<Entity*>* entities);
void updatePositions(std::list<Moveable*>* moveables);