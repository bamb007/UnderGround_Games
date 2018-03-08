#include "Button.h"
#include <iostream>
#include "MouseState.h"

using namespace std;

bool mouseOver = false;
MouseState previousState;

Button::Button()
{
	x = 0;
	y = 0;
	width = 0.3;
	height = 0.1;
}


Button::~Button()
{
}
 
void Button::update(MouseState mouseState)
{
	float leftX = this->x - width / 2;
	float rightX = this->x + width / 2;

	float topY = this->y + height / 2;
	float bottomY = this->y - height / 2;

	mouseOver = !(mouseState.x < leftX || mouseState.x > rightX || mouseState.y > topY || mouseState.y < bottomY);

	if (mouseOver && !mouseState.left && previousState.left) {
		OnClick();
	}

	previousState = mouseState;

	//std::cout << "X: " << x << " Y: " << y << std::endl;
	//std::cout << leftX << std::endl;
}

void Button::draw()
{
	float hWidth = width / 2;
	float hHeight = height / 2;

	if (!mouseOver) {
		glBegin(GL_POLYGON);

		glVertex2f(x - hWidth, y + hHeight);
		glVertex2f(x + hWidth, y + hHeight);
		glVertex2f(x + hWidth, y - hHeight);
		glVertex2f(x - hWidth, y - hHeight);

		glEnd();
	}
	else
	{
		glColor3f(1, 0, 0);
		glBegin(GL_POLYGON);

		glVertex2f(x - hWidth, y + hHeight);
		glVertex2f(x + hWidth, y + hHeight);
		glVertex2f(x + hWidth, y - hHeight);
		glVertex2f(x - hWidth, y - hHeight);

		glEnd();
		glColor3f(1, 1, 1);
	}
}
