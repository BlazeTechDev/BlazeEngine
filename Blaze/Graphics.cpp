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

		uniform mat4 u_ViewProjection;

		out vec4 color;

		void main()
		{
			gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

			WindowsWindow* AppWindow = (WindowsWindow*)window;
			AppWindow->m_Window = s_Window;

			m_ViewportFrameBuffer = new FrameBuffer({ AppWindow->GetWidth(), AppWindow->GetHeight(), 1});
			m_ViewportFrameBuffer->Invalidate();

			shader = new Shader(vertexSource, fragmentSource); 

			attrib = new VertexArray();
			attrib->Create();

			buffer = new VertexBuffer();
			buffer->Create();
			buffer->UploadData(vertices);

			BufferLayout layout = {
				{ ShaderDataType::Float3, "a_Position" }
			};

			buffer->SetLayout(layout);
			attrib->AddVertexBuffer(*buffer);

			e_buffer = new IndexBuffer();
			e_buffer->Create();
			e_buffer->UploadData(indices);
			attrib->SetIndexBuffer(*e_buffer);
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
		m_ViewportFrameBuffer->Bind();

		BeginScene(m_ActiveCamera->GetGraphicalData());

		if (m_EngineGraphicsAPI == GraphicsAPIType::OpenGL)
		{
			OpenGLImpl::OpenGLPreRenderFrameClear();

			for (DrawCallData drawCallData : m_DrawQueue)
			{
				drawCallData.vertexArray->Bind();

				drawCallData.shader->Bind();
				drawCallData.shader->UploadUniformMatrix("u_ViewProjection", m_CurrentViewProjectionMatrix);
				OpenGLImpl::DrawTriangleWithElements(drawCallData.vertexArray->GetIndexBuffer().GetCount());
				drawCallData.shader->UnBind();
			}

			OpenGLImpl::OpenGLPostRenderBufferSwap();
		}

		EndScene();

		m_ViewportFrameBuffer->UnBind();

		m_DrawQueue.clear();
	}

	void Graphics::BeginScene(CameraGraphicalData& camera_data)
	{
		m_CurrentViewMatrix = glm::mat4(1.0f);
		m_CurrentViewMatrix = glm::translate(m_CurrentViewMatrix, camera_data.position)
			* glm::rotate(m_CurrentViewMatrix, camera_data.rotation.x, glm::vec3(1.0f, 0.0f, 0.0f))
			* glm::rotate(m_CurrentViewMatrix, camera_data.rotation.y, glm::vec3(0.0f, 1.0f, 0.0f))
			* glm::rotate(m_CurrentViewMatrix, camera_data.rotation.z, glm::vec3(0.0f, 0.0f, 1.0f));

		m_CurrentProjectionMatrix = glm::mat4(1.0f);
		m_CurrentProjectionMatrix = glm::ortho(-1, 1, -1, 1);

		m_CurrentViewProjectionMatrix = m_CurrentProjectionMatrix * m_CurrentViewMatrix;
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
}