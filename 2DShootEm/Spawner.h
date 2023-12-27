#pragma once

#include "Enemy.h"

class Spawner {
private:
	inline static unsigned int _numberOfEnemiesActive = 0;
	inline static unsigned int _numberOfEnemiesTotal = 0;
	inline static unsigned int _numberOfFriendsActive = 0;
	inline static unsigned int _numberOfFriendsTotal = 0;
public:
	static void CreateEnemy();
};

enum class Side {
	TOP,
	BOTTOM,
	LEFT,
	RIGHT
};