#pragma once
#include <iostream>
#include <vector>
#include "Scene.h"
#include "MouseState.h"

using namespace std;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();
	
	int index;
	void setup();
	void update(MouseState mouseState);
	void draw();
	void SetScene(Scene* scene);
	void ChangeScene(Scene* scene);
	void PreScene();
};

