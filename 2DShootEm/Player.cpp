#include "Player.h"
#include "Projectile.h"
#include "Application.h"
#include "defs.h"

std::function<float(float)> Player::_path(SDL_FPoint point1, SDL_FPoint point2) const
{
	if (point2.x - point1.x == 0) return [k = point1.x](float x) { return k; };
	if (point2.y - point1.y == 0) return [n = point1.y](float x) { return n; };
	
	float k = (point2.y - point1.y) / (point2.x - point1.x);
	float n = point1.y - k * point1.x;

	return [k, n](float x) { return k * x + n; };
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

	Path path = _path(_position, mouse);

	switch (event->button)
	{
		case SDL_BUTTON_LEFT:
			fire(path, direction, "heart");
			break;
		case SDL_BUTTON_RIGHT:
			fire(path, direction, "block");
			break;
		default:
			break;
	}
}

void Player::fire(Path path, Direction direction, const char* texture)
{
	Texture* bullet = Application::getTexture(texture);

	Application::addMoveable(new Projectile(_position, bullet, path, direction));
}