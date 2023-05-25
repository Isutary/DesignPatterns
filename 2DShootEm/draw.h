#pragma once

#include "SDL_render.h"

#include "structs.h"

void prepareClearScene(Color color = Color{ 96, 155, 203, 255 });
void presentScene();
SDL_Texture* loadTexture(const char* filename);
void blit(SDL_Texture* texture, int x, int y);