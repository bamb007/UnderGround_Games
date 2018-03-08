#pragma once
#include "GameScene.h"
#include "Enemy.h"
#include <ctime>
#include <string>
#include "Inventory.h"

bool spawn;
bool talking;
string input;

int x = 3;
int y = 3;

bool previousKeys[91];

int cell_count = 10;
GridItem grid[10][10];

std::clock_t ss;
int updates = 0;

//Spawn player inventory and cell stash
Inventory playerIn = Inventory("Player inventory");
Inventory cellStash = Inventory("Stash");



GameScene::GameScene()
{

	ss = std::clock();

	for (int i = 0; i < cell_count; i++)
	{
		for (int j = 0; j < cell_count; j++)
		{
			grid[i][j] = GridItem(i, j, 0);
		}
	}

	for (int i = 2; i < cell_count - 2; i++)
	{
		grid[i][1] = GridItem(i, 1, 1);
		grid[i][cell_count - 2] = GridItem(i, cell_count - 2, 1);
	}

	for (int i = 1; i < cell_count - 1; i++)
	{
		grid[1][i] = GridItem(1, i, 1);
		grid[cell_count - 2][i] = GridItem(cell_count - 2, i, 1);
	}

	Enemy* enemy = new Enemy(this);
	Enemy* enemy1 = new Enemy(this);

	enemy->x = 4;
	enemy->y = 4;

	enemy1->x = 2;
	enemy1->y = 2;


	entities.push_back(enemy);
	entities.push_back(enemy1);


}


GameScene::~GameScene()
{
}

void GameScene::update(MouseState mouseState) {
	Scene::update(mouseState);

	updates++;

	if (spawn == false)
	{
		playerIn.Display();
		spawn = true;
	}

	if (mouseState.keys[GLFW_KEY_I] && !previousKeys[GLFW_KEY_I])
	{
		playerIn.Display();
	}

	if (x == entities[0]->x && y == entities[0]->y && mouseState.keys[GLFW_KEY_E] && !previousKeys[GLFW_KEY_E])
	{
		talking = true;
		while (talking)
		{
			system("CLS");
			cout << "Player made contact with inmate 0" << endl;

			cout << "Press A to steal from him" << endl;
			cout << "Press E to insult his mom and get yourself killed" << endl;
			getline(cin, input);

			if (input == "a" || input == "A")
			{
				playerIn.RandomSpawnItem(1);
				playerIn.Display();
				talking = false;
			}

			if (input == "e" || input == "E")
			{
				playerIn.ClearInventory();
				playerIn.Display();
				talking = false;
			}
		}
	}

	if (x == entities[1]->x && y == entities[1]->y && mouseState.keys[GLFW_KEY_E] && !previousKeys[GLFW_KEY_E])
	{
		talking = true;
		while (talking)
		{
			system("CLS");
			cout << "Player made contact with inmate 1" << endl;

			cout << "Press A to steal from him" << endl;
			cout << "Press E to insult his mom and get yourself killed" << endl;
			getline(cin, input);

			if (input == "a" || input == "A")
			{
				playerIn.RandomSpawnItem(1);
				playerIn.Display();
				talking = false;
			}

			if (input == "e" || input == "E")
			{
				playerIn.ClearInventory();
				playerIn.Display();
				talking = false;
			}
		}
	}

	if (double(clock() - ss) / CLOCKS_PER_SEC >= 1) {
		//std::cout << "Updates: " << updates << endl;
		updates = 0;
		ss = clock();
	}

	if (mouseState.keys[GLFW_KEY_D] && !previousKeys[GLFW_KEY_D]) {
		if (grid[x + 1][y].type != 1)
		{
			x++;
		}
	}
	else if (mouseState.keys[GLFW_KEY_A] && !previousKeys[GLFW_KEY_A]) {
		if (grid[x - 1][y].type != 1)
		{
			x--;
		}
	}

	if (mouseState.keys[GLFW_KEY_W] && !previousKeys[GLFW_KEY_W]) {
		if (grid[x][y - 1].type != 1)
		{
			y--;
		}
	}
	else if (mouseState.keys[GLFW_KEY_S] && !previousKeys[GLFW_KEY_S]) {
		if (grid[x][y + 1].type != 1)
		{
			y++;
		}
	}

	for (int i = 65; i <= 90; i++)
	{
		previousKeys[i] = mouseState.keys[i];
	}
}

void GameScene::draw() {
	Scene::draw();

	glBegin(GL_LINES);

	for (int i = 1; i < cell_count; i++)
	{
		glVertex2f(-1, i * (2.0 / cell_count) - 1);
		glVertex2f(1, i * (2.0 / cell_count) - 1);

		glVertex2f(i * (2.0 / cell_count) - 1, -1);
		glVertex2f(i * (2.0 / cell_count) - 1, 1);
	}

	glEnd();

	float screenX, screenY;

	for (int i = 0; i < cell_count; i++)
	{
		for (int j = 0; j < cell_count; j++)
		{
			if (grid[i][j].type == 1)
			{
				getPosition(i, j, &screenX, &screenY);
				drawWall(screenX, screenY);
			}
		}
	}

	getPosition(x, y, &screenX, &screenY);

	drawPlayer(screenX, screenY);
}

void GameScene::getPosition(float x, float y, float* screenX, float* screenY)
{
	*screenX = x * (2.0 / cell_count) - (1 - (2.0 / cell_count) / 2);
	*screenY = -(y * (2.0 / cell_count)) + (1 - (2.0 / cell_count) / 2);
}

void GameScene::drawWall(float screenX, float screenY)
{
	float halfSize = (2.0 / cell_count) / 2;

	glBegin(GL_POLYGON);

	glVertex2f(screenX - halfSize, screenY + halfSize);
	glVertex2f(screenX + halfSize, screenY + halfSize);
	glVertex2f(screenX + halfSize, screenY - halfSize);
	glVertex2f(screenX - halfSize, screenY - halfSize);

	glEnd();
}

void GameScene::drawPlayer(float screenX, float screenY) {

	const float DEG2RAD = 3.14159 / 180;
	float radius = 0.01;

	glBegin(GL_POLYGON);

	for (int i = 0; i < 360; i++)
	{
		float degInRad = i * DEG2RAD;
		glVertex2f(screenX + (cos(degInRad) * radius), screenY + (sin(degInRad) * radius) + 0.03);
	}

	glEnd();

	glBegin(GL_LINES);

	glVertex2f(screenX, screenY - radius + 0.03);
	glVertex2f(screenX, screenY - radius - 0.04 + 0.03);

	glVertex2f(screenX, screenY - radius + 0.03);
	glVertex2f(screenX - 0.02, screenY - radius - 0.02 + 0.03);

	glVertex2f(screenX, screenY - radius + 0.03);
	glVertex2f(screenX + 0.02, screenY - radius - 0.02 + 0.03);

	glVertex2f(screenX, screenY - radius - 0.04 + 0.03);
	glVertex2f(screenX - 0.02, screenY - radius - 0.06 + 0.03);

	glVertex2f(screenX, screenY - radius - 0.04 + 0.03);
	glVertex2f(screenX + 0.02, screenY - radius - 0.06 + 0.03);

	glEnd();
}