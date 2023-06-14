#include "Player.h"
#include "Projectile.h"
#include "Application.h"
#include "defs.h"

float Player::_getTheta(SDL_FPoint point1, SDL_FPoint point2) const
{
	if (point2.x == point1.x) return atan(INFINITY);

	float k = (point2.y - point1.y) / (point2.x - point1.x);

	return atan(k);
}

Player::Player(SDL_FPoint position, Texture* texture) : Moveable(position, texture, PLAYER_SPEED), _newPosition(position) { }

void Player::move()
{
	_updatePosition(_newPosition);
	_newPosition = _position;
}

void Player::handleInput(SDL_KeyboardEvent* event)
{
	switch (event->keysym.scancode)
	{
		case SDL_SCANCODE_W:
			_newPosition.y -= _speed;
			break;
		case SDL_SCANCODE_S:
			_newPosition.y += _speed;
			break;
		case SDL_SCANCODE_A:
			_newPosition.x -= _speed;
			break;
		case SDL_SCANCODE_D:
			_newPosition.x += _speed;
			break;
		default:
			break;
	}
}

void Player::handleInput(SDL_MouseButtonEvent* event)
{
	SDL_FPoint mouse{ event->x, event->y };

	Direction direction = _position.x > mouse.x ? LEFT : RIGHT;
	if (_position.x == mouse.x)
	{
		direction = _position.y > mouse.y ? LEFT : RIGHT;
	}

	float theta = _getTheta(_position, mouse);

	switch (event->button)
	{
		case SDL_BUTTON_LEFT:
			fire(theta, direction, "heart");
			break;
		case SDL_BUTTON_RIGHT:
			fire(theta, direction, "block");
			break;
		default:
			break;
	}
}

void Player::fire(float theta, Direction direction, const char* texture)
{
	Texture* bullet = Application::getTexture(texture);

	Application::addMoveable(new Projectile(_position, bullet, theta, direction));
}