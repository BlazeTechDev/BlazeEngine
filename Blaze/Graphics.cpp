#include "blzpch.hpp"
#include "Graphics.hpp"

#include "Application.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "WindowsWindow.hpp"
#include "OpenGLImpl.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Blaze
{

#ifdef BLZ_OPENGL_GRAPHICS
	static GLFWwindow* s_Window = nullptr;

	void Graphics::Initialize(Window* window)
	{
		s_Window = OpenGLImpl::InitializeOpenGL(window);

		WindowsWindow* app_window = (WindowsWindow*)window;
		app_window->m_Window = s_Window;
	}

	void Graphics::Shutdown()
	{
		OpenGLImpl::ShutdownOpenGL();
	}

	void Graphics::Update()
	{
		OpenGLImpl::OpenGLPreRenderBufferSwap();
	}

	void Graphics::SetVSync(bool enabled)
	{
		OpenGLImpl::OpenGLSetVSync(enabled);
	}
#endif

}