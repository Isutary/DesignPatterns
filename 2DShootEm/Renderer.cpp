#include "SDL_render.h"

#include "Renderer.h"
#include "Application.h"

void Renderer::clearScene(Color color)
{
	SDL_SetRenderDrawColor(Application::getRenderer(), color.r, color.g, color.b, color.a);
	SDL_RenderClear(Application::getRenderer());
}

void Renderer::drawEntities()
{
	std::list<Entity*>* entities = Application::getEntities();

	for (auto it = entities->begin(); it != entities->end(); it++)
	{
		SDL_FRect dest{ (*it)->getPosition().x, (*it)->getPosition().y, (*it)->getSize().h, (*it)->getSize().w};

		SDL_RenderCopyF(Application::getRenderer(), (*it)->getTexture(), NULL, &dest);
	}
}

void Renderer::updateMoveablesPositions()
{
	std::list<Moveable*>* moveables = Application::getMoveables();

	for (auto it = moveables->begin(); it != moveables->end(); it++) (*it)->move();
}

void Renderer::removeMoveables()
{
	Application::removeExpiredMoveables();
}

void Renderer::presentScene()
{
	SDL_RenderPresent(Application::getRenderer());
}

void Renderer::updateScene()
{
	clearScene();
	drawEntities();
	updateMoveablesPositions();
	removeMoveables();
	presentScene();
}