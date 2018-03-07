#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
#include "MouseState.h"

using namespace std;

class Entity
{
public:
	Entity();
	~Entity();
	virtual void update(MouseState mouseState) {
		cout << "Default Entity update" << endl;
	}

	virtual void draw() {}
	int x, y;
	float width, height;
};

