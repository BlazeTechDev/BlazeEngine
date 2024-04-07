#pragma once

#include "Window.hpp"

#include <GLFW/glfw3.h>

namespace Blaze
{
	class OpenGLImpl
	{
	public:
		static GLFWwindow* InitializeOpenGL(Window* window);
		static void OpenGLPreRenderBufferSwap();

		static void OpenGLSetVSync(bool enabled);

		static void ShutdownOpenGL();
	};
}