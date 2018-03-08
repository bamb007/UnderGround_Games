#include "MenuScene.h"
#include "PlayButton.h"

MenuScene::MenuScene()
{
	Entity* playButton = new PlayButton();

	playButton->x = 0;
	playButton->y = -0.5;

	entities.push_back(playButton);
}


MenuScene::~MenuScene()
{
}
