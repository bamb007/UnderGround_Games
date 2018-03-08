#include "Enemy.h"
#include "Inventory.h"

Enemy::Enemy(GameScene* gameScene) : Entity::Entity()
{
	this->gameScene = gameScene;
}
Enemy::~Enemy()
{
}

void Enemy::MakeInventory()
{
	inventory.RandomSpawnItem(3);
}



void Enemy::Movement()
{
	srand(rand() % 1000 + 1);
	rnd = rand() % 4 + 1;
	if (rnd == 1)
	{
		if (gameScene->grid[x + 1][y].type != 1)
		{
			x++;
		}
	}
	else if (rnd == 2)
	{
		if (gameScene->grid[x - 1][y].type != 1)
		{
			x--;
		}
	}
	else if (rnd == 3)
	{
		if (gameScene->grid[y + 1][x].type != 1)
		{
			y++;
		}
	}
	else if (rnd == 4)
	{
		if (gameScene->grid[y - 1][x].type != 1)
		{
			y--;
		}
	}
}

void Enemy::update(MouseState mouseState)
{	
	if (spawn == false)
	{
		MakeInventory();
		spawn = true;
	}
	if (baseSec >= 0)
	{
		baseSec += 1;
	}
	if (baseSec > 60000)
	{
		baseSec = 0;
		Movement();
	}
}

void Enemy::draw()
{
	float screenX, screenY;

	gameScene->getPosition(x, y, &screenX, &screenY);

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
