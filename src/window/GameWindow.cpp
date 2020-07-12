//
// Created by cjohnson on 7/12/20.
//

#include "GameWindow.h"

void cccgame::GameWindow::GlobalGLFWErrorCallback(int error, const char *description)
{
	std::cerr << "GLFW Error [" << error << "]: " << description << std::endl;
}

uint32_t cccgame::GameWindow::ConstructWindowElements()
{
	glfwSetErrorCallback(cccgame::GameWindow::GlobalGLFWErrorCallback);

	if(!InitializeGLFW() || !InitializeGLAD())
		return -1;

	std::cout << "Succesfully Constructed Window Elements" << std::endl;

	return 0;
}

void cccgame::GameWindow::WindowLoop()
{
	if(!windowHandle)
		return;

	glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

	while(!glfwWindowShouldClose(windowHandle))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(windowHandle);
		glfwPollEvents();
	}
}

uint32_t cccgame::GameWindow::CleanupWindowElements()
{
	glfwDestroyWindow(windowHandle);
	glfwTerminate();

	return 0;
}

uint32_t cccgame::GameWindow::InitializeGLFW()
{
	std::cout << "Initializing GLFW..." << std::endl;

	if(!glfwInit())
	{
		std::cerr << "Unable to Initialize GLFW..." << std::endl;

		return -1;
	}

	HandleGLFWWindowHints();

	if(!ConstructGLFWWindow())
		return -1;

	return 0;
}

uint32_t cccgame::GameWindow::InitializeGLAD()
{
	glfwMakeContextCurrent(windowHandle);

	if(!gladLoadGL())
	{
		std::cerr << "Unable to load OpenGL from GLAD." << std::endl;

		glfwDestroyWindow(windowHandle);
		glfwTerminate();

		return -1;
	}

	return 0;
}

void cccgame::GameWindow::HandleGLFWWindowHints()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, OPENGL_MAJOR_VERSION);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, OPENGL_MINOR_VERSION);
	
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
}

uint32_t cccgame::GameWindow::ConstructGLFWWindow()
{
	windowHandle = glfwCreateWindow(1280, 720, "CatacombCrawlersC", nullptr, nullptr);
	if(!windowHandle)
	{
		std::cerr << "Unable to Create the GLFW Window" << std::endl;

		glfwTerminate();

		return -1;
	}

	return 0;
}

GLFWwindow *cccgame::GameWindow::GetWindowHandle()
{
	return windowHandle;
}
