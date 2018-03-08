#include <iostream>
#include <GLFW/glfw3.h>
#include "SceneManager.h"
#include "Globals.h"
#include "MenuScene.h"
#include <Windows.h>

SceneManager sceneManager;
bool keys[91];

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	keys[key] = action == GLFW_PRESS;
}


int main(void)
{
	HWND consoleWindow = GetConsoleWindow();
	SetWindowPos(consoleWindow, 0, 1000, 250, 300, 640, SWP_NOZORDER);


	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	int windowWidth = 640;
	int windowHeight = 640;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(windowWidth, windowHeight, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwSetWindowPos(window, 1000 - 640, 250);

	glfwSetKeyCallback(window, key_callback);

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	for (int i = 65; i <= 90; i++)
	{
		keys[i] = false;
	}

	Globals::sceneManager = &sceneManager;
	Globals::sceneManager->SetScene(new MenuScene());
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);

		double worldX, worldY;

		worldX = (xpos / windowWidth) * 2 - 1;
		worldY = -((ypos / windowHeight) * 2 - 1);

		int state = glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_LEFT);

		MouseState mouseState = MouseState(worldX, worldY, state == GLFW_PRESS, keys);

		Globals::sceneManager->update(mouseState);
		Globals::sceneManager->draw();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}