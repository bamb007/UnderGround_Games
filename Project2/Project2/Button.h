#pragma once
#include "Entity.h"

class Button : public Entity
{
public:
	Button();
	~Button();
	virtual void OnClick() {
	}

	void update(MouseState mouseState);
	void draw();

private:
	bool mouseOver;
	MouseState previousState;
};

