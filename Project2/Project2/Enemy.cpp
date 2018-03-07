#include "Enemy.h"

Enemy::~Enemy()
{
}

void Enemy::update(MouseState mouseState)
{
	if (gameScene->grid[x + 1][y].type != 1)
	{
		x++;
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
