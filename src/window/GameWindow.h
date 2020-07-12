//
// Created by cjohnson on 7/12/20.
//

#ifndef CATACOMBCRAWLERSC_GAMEWINDOW_H
#define CATACOMBCRAWLERSC_GAMEWINDOW_H

static const int OPENGL_MAJOR_VERSION = 3;
static const int OPENGL_MINOR_VERSION = 2;

#include <glad/glad.h>
#include <glfw/glfw3.h>

#include <iostream>

#include "utility/Logger.h"

namespace cccgame
{
	class GameWindow
	{
	public:
		static void GlobalGLFWErrorCallback(int error, const char* description);

		uint32_t ConstructWindowElements();
		void WindowLoop();
		uint32_t CleanupWindowElements();

		GLFWwindow *GetWindowHandle();
	private:
		GLFWwindow *windowHandle;

		uint32_t InitializeGLFW();
		void HandleGLFWWindowHints();
		uint32_t ConstructGLFWWindow();
		uint32_t InitializeGLAD();
	};
}

#endif //CATACOMBCRAWLERSC_GAMEWINDOW_H
