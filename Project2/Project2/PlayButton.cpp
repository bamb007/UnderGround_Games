#include "PlayButton.h"
#include "Globals.h"
#include "Scene.h"
#include "GameScene.h"

#include <iostream>

PlayButton::PlayButton()
{
}


PlayButton::~PlayButton()
{
}

void PlayButton::OnClick() {
	Globals::sceneManager->ChangeScene(new GameScene());
}