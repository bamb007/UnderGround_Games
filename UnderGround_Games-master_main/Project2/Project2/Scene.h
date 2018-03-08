#pragma once
#include <vector>
#include "Entity.h"
#include "MouseState.h"

using namespace std;

class Scene
{
public:
	~Scene();
	virtual void update(MouseState mouseState);
	virtual void draw();
	
protected:
	Scene();
	vector<Entity*> entities;
};

