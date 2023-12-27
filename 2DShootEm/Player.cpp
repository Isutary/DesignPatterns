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

void Player::_fire(SDL_FPoint mouse, const char* texture)
{
	Texture* bullet = Application::getTexture(texture);

	SDL_FPoint position = SDL_FPoint{ getPosition().x + (getSize().w / 2 - bullet->getSize().w / 2) + 2, getPosition().y + (getSize().h / 2 - bullet->getSize().h / 2)};

	Direction direction = position.x > mouse.x ? LEFT : RIGHT;
	if (position.x == mouse.x)
	{
		direction = position.y > mouse.y ? LEFT : RIGHT;
	}

	float theta = _getTheta(position, mouse);

	Application::addMoveable(new Projectile(position, bullet, theta, direction));
}

Player::Player(SDL_FPoint position, Texture* texture) : Moveable(position, texture, PLAYER_SPEED), _newPosition(position) { }

void Player::move()
{
	_updatePosition(_newPosition);
	_newPosition = getPosition();
}

void Player::handleInput(const Uint8* state)
{
	if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_D])
	{
		_newPosition.y -= _speed;
		_newPosition.x += _speed;
		return;
	}
	if (state[SDL_SCANCODE_W] && state[SDL_SCANCODE_A])
	{
		_newPosition.y -= _speed;
		_newPosition.x -= _speed;
		return;
	}
	if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_D])
	{
		_newPosition.y += _speed;
		_newPosition.x += _speed;
		return;
	}
	if (state[SDL_SCANCODE_S] && state[SDL_SCANCODE_A])
	{
		_newPosition.y += _speed;
		_newPosition.x -= _speed;
		return;
	}
	if (state[SDL_SCANCODE_W])
	{
		_newPosition.y -= _speed;
		return;
	}
	if (state[SDL_SCANCODE_S])
	{
		_newPosition.y += _speed;
		return;
	}
	if (state[SDL_SCANCODE_D])
	{
		_newPosition.x += _speed;
		return;
	}
	if (state[SDL_SCANCODE_A])
	{
		_newPosition.x -= _speed;
		return;
	}
}

void Player::handleInput(int state, SDL_Point mouse)
{
	SDL_FPoint fMouse = SDL_FPoint{ (float)mouse.x, (float)mouse.y };

	switch (state)
	{
		case SDL_BUTTON_LEFT:
			_fire(fMouse, "heart");
			break;

		case SDL_BUTTON_RIGHT:
			_fire(fMouse, "block");
			break;

		default:
			break;
	}
}