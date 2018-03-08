#pragma once
#include "Scene.h"
#include "GridItem.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();
	void update(MouseState mouseState);
	void draw();
	void getPosition(float x, float y, float* screenX, float* screenY);
	void drawWall(float screenX, float screenY);
	void drawPlayer(float screenX, float screenY);
	GridItem grid[10][10];
};

