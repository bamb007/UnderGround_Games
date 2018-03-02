#include <iostream>
#include <GLFW/glfw3.h>

struct GridItem
{
	float x;
	float y;

	int type;

	GridItem() {
		x = 0;
		y = 0;
		type = 0;
	}

	GridItem(float _x, float _y, int _type)
	{
		x = _x;
		y = _y;
		type = _type;

	}
};

int printc = 40;

int x = 3;
int y = 3;
GridItem grid[20][20];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		if (grid[x + 1][y].type != 1)
		{
			x++;
		}
	}
	else if (key == GLFW_KEY_A && action == GLFW_PRESS) {
		if (grid[x - 1][y].type != 1)
		{
			x--;
		}
	}

	if (key == GLFW_KEY_W && action == GLFW_PRESS) {
		if (grid[x][y - 1].type != 1)
		{
			y--;
		}		
	}
	else if (key == GLFW_KEY_S && action == GLFW_PRESS) {
		if (grid[x][y + 1].type != 1)
		{
			y++;
		}
	}
}

void getPosition(float x, float y, float* screenX, float* screenY)
{
	*screenX = x * 0.1 - 0.95;
	*screenY = -(y * 0.1) + 0.95;

	if (printc) {
		std::cout << "X: " << x << " Y: " << y << " ScreenX: " << *screenX << " ScreenY: " << *screenY << std::endl;
		printc--;
	}
	
}

void drawWall(float screenX, float screenY)
{
	glBegin(GL_POLYGON);

	glVertex2f(screenX - 0.05, screenY + 0.05);
	glVertex2f(screenX + 0.05, screenY + 0.05);
	glVertex2f(screenX + 0.05, screenY - 0.05);
	glVertex2f(screenX - 0.05, screenY - 0.05);

	glEnd();
}

void drawPlayer(float screenX, float screenY) {

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

int main(void)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			grid[i][j] = GridItem(i, j, 0);
		}
	}

	for (int i = 2; i < 18; i++)
	{
		grid[i][1] = GridItem(i, 1, 1);
		grid[i][18] = GridItem(i, 18, 1);
	}

	for (int i = 1; i < 19; i++)
	{
		grid[1][i] = GridItem(1, i, 1);
		grid[18][i] = GridItem(18, i, 1);
	}

	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(640, 640, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		for (int i = 1; i < 20; i++)
		{
			glBegin(GL_LINES);

			glVertex2f(i * 0.1 - 1, 1);
			glVertex2f(i * 0.1 - 1, -1);

			glEnd();

			glBegin(GL_LINES);

			glVertex2f(-1, i * 0.1 - 1);
			glVertex2f(1, i * 0.1 - 1);

			glEnd();
		}

		float screenX, screenY;

		getPosition(x, y, &screenX, &screenY);

		drawPlayer(screenX, screenY);

		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				GridItem item = grid[i][j];

				if (item.type == 1) {
					getPosition(i, j, &screenX, &screenY);
					drawWall(screenX, screenY);
				}
			}
		}


		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	

	glfwTerminate();
}