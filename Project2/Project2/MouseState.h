#pragma once
class MouseState
{
public:
	MouseState();
	MouseState(float x, float y, bool left, bool keys[]);
	~MouseState();

	float x, y;
	bool left;
	bool keys[91];
};

