#include "blzpch.hpp"
#include "Graphics.hpp"

#include "Application.hpp"
#include "Log.hpp"
#include "Window.hpp"
#include "Buffer.hpp"
#include "Shader.hpp"
#include "WindowsWindow.hpp"
#include "OpenGLImpl.hpp"

#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Blaze
{
	static GLFWwindow* s_Window = nullptr;
	
	const std::vector<float> vertices = { -0.5f, -0.5f, 0,
						0.5f, -0.5f, 0,
						0.5f, 0.5f, 0,
						-0.5f, 0.5f, 0,};

	const std::vector<int> indices = { 0, 1, 2, 2, 3, 0 };

	const std::string vertexSource = R"(
		#version 330 core
		layout (location = 0) in vec3 a_Position;
		layout (location = 1) in vec2 a_UV;

		uniform mat4 u_View;

		out vec4 color;

		void main()
		{
			gl_Position = vec4(a_Position.x, a_Position.y, a_Position.z, 1.0);
			color = vec4(1,1,1,1);
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
	IndexBuffer* e_buffer = nullptr;
	Shader* shader = nullptr;

	Graphics* Graphics::s_Instance = nullptr;

	FrameBuffer* m_SceneViewportFrameBuffer = nullptr;

	VertexArray* attrib = nullptr;

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

			attrib = new VertexArray();
			attrib->Create();

			buffer = new VertexBuffer();
			buffer->Create();
			buffer->UploadData(&vertices);

			BufferLayout layout = {
				{ ShaderDataType::Float3, "a_Position" }
			};

			buffer->SetLayout(&layout);
			attrib->AddVertexBuffer(buffer);

			e_buffer = new IndexBuffer();
			e_buffer->Create();
			e_buffer->UploadData(&indices);
			attrib->SetIndexBuffer(e_buffer);

			DrawCallData data = { attrib, shader };

			Submit(data);
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
			for (DrawCallData drawCallData : m_DrawQueue)
			{
				OpenGLImpl::OpenGLPreRenderBufferSwap();
				drawCallData.vertexArray->Bind();

				drawCallData.shader->UploadUniformMatrix("u_View", m_CurrentViewMatrix);

				drawCallData.shader->Bind();
				OpenGLImpl::DrawTriangleWithElements(drawCallData.vertexArray->GetIndexBuffer()->GetCount());
				drawCallData.shader->UnBind();
			}
		}
	}

	void Graphics::BeginScene(CameraGraphicalData camera_data)
	{
		glm::mat4 viewMatrix = glm::mat4(1.0f);
		viewMatrix = glm::translate(viewMatrix, camera_data.position);
		viewMatrix = glm::rotate(viewMatrix, camera_data.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f));
		viewMatrix = glm::rotate(viewMatrix, camera_data.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f));
		viewMatrix = glm::rotate(viewMatrix, camera_data.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

		m_CurrentViewMatrix = viewMatrix;
	}

	void Graphics::Submit(DrawCallData drawCallData)
	{
		m_DrawQueue.push_back(drawCallData);
	}

	void Graphics::EndScene()
	{
		
	}

	void Graphics::Flush()
	{
		m_DrawQueue.clear();
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