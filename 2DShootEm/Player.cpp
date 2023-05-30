#include "Player.h"
#include "Projectile.h"
#include "draw.h"
#include "Application.h"

Player::Player(SDL_Point position, SDL_Texture* texture) : Moveable(position, texture)
{ 
	_speed = 40;
}

void Player::move()
{
}

void Player::fire()
{
	Projectile* bullet = new Projectile(_position, loadTexture("heart.png"));
	Application::addMoveable(bullet);
}
