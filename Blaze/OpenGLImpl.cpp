#include "blzpch.hpp"
#include "OpenGLImpl.hpp"

#include "Log.hpp"
#include "WindowEvent.hpp"
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"

#include <glad/glad.h>

namespace Blaze
{
	static GLFWwindow* m_Window = nullptr;

	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		BLZ_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	GLFWwindow* OpenGLImpl::InitializeOpenGL(Window* window)
	{
		if (!s_GLFWInitialized)
		{
			int success = glfwInit();
			BLZ_CORE_ASSERT(success, "could not initialize GLFW");
			glfwSetErrorCallback(GLFWErrorCallback);

			s_GLFWInitialized = true;
		}

		m_Window = glfwCreateWindow((int)window->GetWidth(), (int)window->GetHeight(), window->GetTitle().c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		BLZ_CORE_ASSERT(status, "failed to initialize glad")
			glfwSetWindowUserPointer(m_Window, window->GetData());
		window->SetVSync(true);

		//set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			data.Width = width;
			data.Height = height;

			WindowResizedEvent event(width, height);
			data.EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			WindowClosedEvent event;
			data.EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				KeyPressedEvent event(key, 0);
				data.EventCallback(event);
				break;
			}
			case GLFW_RELEASE:
			{
				KeyReleasedEvent event(key);
				data.EventCallback(event);
				break;
			}
			case GLFW_REPEAT:
			{
				KeyPressedEvent event(key, 1);
				data.EventCallback(event);
				break;
			}
			}
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow* window, unsigned int keycode)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
			KeyTypedEvent event(keycode);
			data.EventCallback(event);
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow* window, int button, int action, int mods)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			switch (action)
			{
			case GLFW_PRESS:
			{
				MouseButtonPressedEvent event(button);
				data.EventCallback(event);
			}
			case GLFW_RELEASE:
			{
				MouseButtonReleasedEvent event(button);
				data.EventCallback(event);
			}
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xOffset, double yOffset)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)xOffset, (float)yOffset);
			data.EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xPos, double yPos)
		{
			WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)xPos, (float)yPos);
			data.EventCallback(event);
		});

		return m_Window;
	}

	void OpenGLImpl::OpenGLPreRenderBufferSwap()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void OpenGLImpl::OpenGLSetVSync(bool enabled)
	{
		glfwSwapInterval((int)enabled);
	}
	
	void OpenGLImpl::ShutdownOpenGL()
	{
		glfwDestroyWindow(m_Window);
	}
}