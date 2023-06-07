#pragma once

#include "structs.h"

class Renderer {
private:
	void clearScene(Color color = Color{ 96, 155, 203, 255 });
	void drawEntities();
	void updateMoveablesPositions();
	void removeMoveables();
	void presentScene();
public:
	void updateScene();
};