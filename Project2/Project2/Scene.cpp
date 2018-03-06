#include "Scene.h"

vector<Entity*> entities;

Scene::Scene()
{
}

Scene::~Scene()
{
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


