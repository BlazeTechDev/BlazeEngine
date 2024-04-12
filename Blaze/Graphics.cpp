#include "blzpch.hpp"
#include "Graphics.hpp"

#include "Application.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"
#include "WindowsWindow.hpp"
#include "OpenGLImpl.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Blaze
{
	static GLFWwindow* s_Window = nullptr;
	
	const std::vector<float> vertices = { -0.5f, -0.5f, 0, 1,0.3f,0.3f,1,
						0.5f, -0.5f, 0, 0.3f,1,0.3f,1,
						0, 0.5, 0, 0.3f,0.3f,1,1, };

	const std::vector<int> indices = { 0, 1, 2 };

	const std::string vertexSource = R"(
		#version 330 core
		layout (location = 0) in vec3 a_Position;
		layout (location = 1) in vec4 a_Color;

		out vec4 color;

		void main()
		{
			gl_Position = vec4(a_Position.x, a_Position.y, a_Position.z, 1.0);
			color = a_Color;
		}
	)";

	const std::string fragmentSource = R"(
		#version 330 core
		in vec4 color;

		out vec4 FragColor;

		void main()
		{
			FragColor = color;
		} 
	)";

	VertexBuffer* buffer = nullptr;
	ElementBuffer* e_buffer = nullptr;
	Shader* shader = nullptr;

	Graphics* Graphics::s_Instance = nullptr;

	FrameBuffer* m_SceneViewportFrameBuffer = nullptr;

	AttributeArray* attrib = nullptr;

	Graphics::Graphics()
	{
		BLZ_CORE_ASSERT(!s_Instance, "graphics instance already exists");
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

			shader = new Shader(vertexSource, fragmentSource); 

			attrib = new AttributeArray();
			attrib->Create();
			attrib->Bind();

			buffer = new VertexBuffer();
			buffer->Create();
			buffer->Bind();
			buffer->UploadData(&vertices);

			BufferLayout layout = {
				{ ShaderDataType::Float3, "a_Position" },
				{ ShaderDataType::Float4, "a_Color" }
			};

			attrib->SetLayout(&layout);
			attrib->CompileLayouts();

			e_buffer = new ElementBuffer();
			e_buffer->Create();
			e_buffer->Bind();
			e_buffer->UploadData(&indices);
		}
	}

	void Graphics::Shutdown()
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			delete shader;
			OpenGLImpl::ShutdownOpenGL();
		}
	}

	void Graphics::Update()
	{
		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			OpenGLImpl::OpenGLPreRenderBufferSwap();
			attrib->Bind();

			shader->Bind();
			OpenGLImpl::DrawTriangleWithElements();
			shader->UnBind();
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