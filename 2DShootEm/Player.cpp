#include "Player.h"
#include "Projectile.h"
#include "Application.h"
#include "defs.h"

Player::Player(SDL_Point position, Texture* texture) : Moveable(position, texture, PLAYER_SPEED), _newPosition(position) { }

void Player::move()
{
	_updatePosition(_newPosition);
	_newPosition = _position;
}

void Player::handleInput(SDL_KeyboardEvent* event)
{
	switch (event->keysym.scancode)
	{
		case SDL_SCANCODE_UP:
			if (event->repeat != 0) break;
			fire(UP);
			break;
		case SDL_SCANCODE_DOWN:
			if (event->repeat != 0) break;
			fire(DOWN);
			break;
		case SDL_SCANCODE_LEFT:
			if (event->repeat != 0) break;
			fire(LEFT);
			break;
		case SDL_SCANCODE_RIGHT:
			if (event->repeat != 0) break;
			fire(RIGHT);
			break;
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

void Player::fire(Direction direction)
{
	SDL_Point position{};
	Texture* bullet = Application::getTexture("heart");

	switch (direction)
	{
		case UP:
			position.x = _position.x + getSize().w / 2 - bullet->getSize().w / 2;
			position.y = _position.y - 16;
			break;
		case DOWN:
			position.x = _position.x + getSize().w / 2 - bullet->getSize().w / 2;
			position.y = _position.y + getSize().h;
			break;
		case LEFT:
			position.x = _position.x - 16;
			position.y = _position.y + getSize().h / 2 - bullet->getSize().h / 2;
			break;
		case RIGHT:
			position.x = _position.x + getSize().w;
			position.y = _position.y + getSize().h / 2 - bullet->getSize().h / 2;
			break;
		default:
			break;
	}

	Application::addMoveable(new Projectile(position, bullet, direction));
}