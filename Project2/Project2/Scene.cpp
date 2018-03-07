#include "Scene.h"

vector<Entity*> entities;

Scene::Scene()
{
}

Scene::~Scene()
{
	for (Entity* var: entities)
	{
		delete var;
	}

	delete &entities;
}

void Scene::update(MouseState mouseState)
{
	for (Entity* entity: entities)
	{
		entity->update(mouseState);
	}
}

void Scene::draw()
{
	for (Entity* entity: entities)
	{
		entity->draw();
	}
}


