#include "MouseState.h"

MouseState::MouseState() {
	this->x = 0;
	this->y = 0;
	this->left = false;
}

MouseState::MouseState(float x, float y, bool left, bool keys[])
{
	this->x = x;
	this->y = y;
	this->left = left;

	for (int i = 65; i <= 90; i++)
	{
		this->keys[i] = keys[i];
	}
}

MouseState::~MouseState()
{
}
