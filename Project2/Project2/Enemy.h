#pragma once
#include "Entity.h"
#include "GameScene.h"

class Enemy :
	public Entity
{
public:
	Enemy(GameScene* gameScene) : Entity::Entity() {
		this->gameScene = gameScene;
	}
	~Enemy();

	void update(MouseState mouseState);
	void draw();
	GameScene* gameScene;
};

