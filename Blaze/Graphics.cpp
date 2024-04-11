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
	static GLFWwindow* s_Window = nullptr;
	
	Graphics* Graphics::s_Instance = nullptr;

	FrameBuffer* m_SceneViewportFrameBuffer = nullptr;

	Graphics::Graphics()
	{
		BLZ_CORE_ASSERT(!s_Instance, "application already exists");
		s_Instance = this;
	}

	void Graphics::Initialize(Window* window)
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			s_Window = OpenGLImpl::InitializeOpenGL(window);

			WindowsWindow* app_window = (WindowsWindow*)window;
			app_window->m_Window = s_Window;

			m_SceneViewportFrameBuffer = new FrameBuffer();
			m_SceneViewportFrameBuffer->Create();
		}
	}

	void Graphics::Shutdown()
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			OpenGLImpl::ShutdownOpenGL();
		}
	}

	void Graphics::Update()
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			OpenGLImpl::OpenGLPreRenderBufferSwap();
		}
	}

	void Graphics::SetVSync(bool enabled)
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			OpenGLImpl::OpenGLSetVSync(enabled);
		}
	}

	void Graphics::BindSceneViewportFrameBuffer()
	{
		m_SceneViewportFrameBuffer->Bind();
	}

	void Graphics::UnBindSceneViewportFrameBuffer()
	{
		m_SceneViewportFrameBuffer->UnBind();
	}
}