#include "SceneManager.h"

vector<Scene*> scenes;
Scene* nextScene;

SceneManager::SceneManager()
{
}


SceneManager::~SceneManager()
{

}

void SceneManager::setup() 
{

}

void SceneManager::update(MouseState mouseState)
{
	scenes.back()->update(mouseState);

	if (nextScene != NULL) {
		scenes.push_back(nextScene);
		nextScene = NULL;
	}
}

void SceneManager::draw()
{
	scenes.back()->draw();
}

void SceneManager::SetScene(Scene* scene) {
	scenes.push_back(scene);
}

void SceneManager::ChangeScene(Scene* scene)
{
	nextScene = scene;
}

void SceneManager::PreScene()
{
	Scene* trash = scenes.back();

	scenes.pop_back();

	delete trash;
}
