#include <cmath>

#include "Enemy.h"
#include "Application.h"
#include "defs.h"
#include "collisionDetector.h"

bool Enemy::_boundCheck()
{
	if (collisionDetector(Application::getPlayer()->getFRect(), this->getFRect()))
	{
		_perish();
		return true;
	}

	return false;
}

float Enemy::_getTheta(SDL_FPoint point1, SDL_FPoint point2)
{
	float k = (point2.y - point1.y) / (point2.x - point1.x);

	return atan(k);
}

SDL_FPoint Enemy::_distance()
{
	SDL_FPoint point{};

	float theta = _getTheta(getPosition(), Application::getPlayer()->getPosition());

	Direction direction = getPosition().x > Application::getPlayer()->getPosition().x ? LEFT : RIGHT;
	if (getPosition().x == Application::getPlayer()->getPosition().x)
	{
		direction = getPosition().y > Application::getPlayer()->getPosition().y ? LEFT : RIGHT;
	}

	switch (direction)
	{
		case LEFT:
			point.x = cos(theta) * _speed;
			point.y = sin(theta) * _speed;
			break;
		case RIGHT:
			point.x = cos(theta) * (-_speed);
			point.y = sin(theta) * (-_speed);
			break;
		default:
			break;
	}

	return point;
}

Enemy::Enemy(SDL_FPoint position, Texture* texture) : Moveable(position, texture, ENEMY_SPEED) { }

void Enemy::move()
{
	if (_boundCheck()) return;

	SDL_FPoint position = getPosition();
	SDL_FPoint path = _distance();

	position.x -= path.x;
	position.y -= path.y;

	_updatePosition(position);
}