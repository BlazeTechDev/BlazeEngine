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

		BLZ_CORE_INFO("OpenGL Renderer version: {0} {1} initialized", (char*)glGetString(GL_VENDOR), (char*)glGetString(GL_RENDERER));

		return m_Window;
	}

	void OpenGLImpl::OpenGLPostRenderBufferSwap()
	{
		glfwSwapBuffers(m_Window);
		glfwPollEvents();
	}

	void OpenGLImpl::OpenGLPreRenderFrameClear()
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glClearColor(0.7f, 0.3f, 0.3f, 1);
	}

	void OpenGLImpl::OpenGLSetVSync(bool enabled)
	{
		glfwSwapInterval((int)enabled);
	}
	
	void OpenGLImpl::ShutdownOpenGL()
	{
		glfwDestroyWindow(m_Window);
	}

	void OpenGLImpl::DrawTriangleWithArrays(int count)
	{
		glDrawArrays(GL_TRIANGLES, 0, count);
	}

	void OpenGLImpl::DrawTriangleWithElements(int count)
	{
		glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, (void*)0);
	}

	int OpenGLImpl::GetOpenGLDataType(BlazeDataType type)
	{
		switch (type)
		{
		case BlazeDataType::BLZ_FLOAT:
			return GL_FLOAT;
		case BlazeDataType::BLZ_INT:
			return GL_INT;
		case BlazeDataType::BLZ_DOUBLE:
			return GL_DOUBLE;
		}

		return GL_NONE;
	}

	unsigned int OpenGLImpl::CreateOpenGLShader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		unsigned int program = 0;
		// Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = (const GLchar*)vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Vertex Shader error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");

			// We don't need the shader anymore.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return 0;
		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = (const GLchar*)fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Fragment Shader error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");
			// We don't need the shader anymore.
			glDeleteShader(fragmentShader);
			// Either of them. Don't leak shaders.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return 0;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.

		program = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(program, vertexShader);
		glAttachShader(program, fragmentShader);

		// Link our program
		glLinkProgram(program);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(program, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Shader Program error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");

			// We don't need the program anymore.
			glDeleteProgram(program);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return 0;
		}

		// Always detach shaders after a successful link.
		glDetachShader(program, vertexShader);
		glDetachShader(program, fragmentShader);

		return program;
	}
}