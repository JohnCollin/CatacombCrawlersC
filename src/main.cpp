//
// Created by cjohnson on 7/12/20.
//

#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace ccc
{
	void errorCallback(int error, const char* description)
	{
		std::cerr << "GLFW Error " << error << ": " << description << std::endl;
	}

	GLFWwindow *initialize()
	{
		if(!glfwInit())
		{
			std::cerr << "Unable to Initialize GLFW!" << std::endl;

			return nullptr;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

		GLFWwindow *window = glfwCreateWindow(1280, 720, "CatacombCrawlersC", nullptr, nullptr);
		if(!window)
		{
			std::cerr << "Unable to Create the GLFW Window!" << std::endl;
			glfwTerminate();

			return nullptr;
		}

		glfwMakeContextCurrent(window);

		if(!gladLoadGL())
		{
			std::cerr << "Unable to initialize GLAD!" << std::endl;
			glfwDestroyWindow(window);
			glfwTerminate();

			return nullptr;
		}

		return window;
	}
}

int main()
{
	glfwSetErrorCallback(ccc::errorCallback);

	GLFWwindow *window = ccc::initialize();
	if(!window)
	{
		return 0;
	}

	glClearColor(0.15f, 0.6f, 0.4f, 1.0f);

	while(!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}