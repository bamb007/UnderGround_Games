#pragma once
#include "Entity.h"
#include "GameScene.h"
#include <Windows.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Inventory.h"

class Enemy :
	public Entity
{
private:
	int rnd;
	int baseSec;
	bool spawn;
public:	
	Inventory inventory = Inventory("Inmate inventory");
	Enemy(GameScene* gameScene);
	~Enemy();

	void MakeInventory();
	void Movement();
	void update(MouseState mouseState);
	void draw();
	GameScene* gameScene;
};

