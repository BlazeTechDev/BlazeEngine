#pragma once

#include "Core.hpp"
#include "Window.hpp"
#include "Buffer.hpp"

#include <glm.hpp>

namespace Blaze
{
	enum BLAZE_API GraphicsAPIType
	{
		OpenGL = 0,
		Vulkan = 1,
		Metal = 2,
		DirectX = 3
	};

	struct BLAZE_API CameraGraphicalData
	{
		glm::vec3 position;
		glm::vec3 rotation;
	};

	struct BLAZE_API DrawCallData
	{
		VertexArray* vertexArray;
		Shader* shader;

		DrawCallData(VertexArray* passVertexArray, Shader* passShader) : vertexArray(passVertexArray), shader(passShader) {};
	};

	class BLAZE_API Graphics
	{
	public:
		Graphics();

		void Initialize(Window* window);
		void Shutdown();
		void Update();

		//scene rendering functions
		void BeginScene(CameraGraphicalData camera_data);
		void Submit(DrawCallData drawCallData);
		void EndScene();
		void Flush();

		void SetVSync(bool enabled);

		const GraphicsAPIType GetEngineGraphicsAPI() { return m_EngineGraphicsAPI; }

		FrameBuffer* GetViewportFrameBuffer() { return m_ViewportFrameBuffer; }

		static Graphics* Get() { return s_Instance; }
		
	private:
		
		const static GraphicsAPIType m_EngineGraphicsAPI = GraphicsAPIType::OpenGL;

		static Graphics* s_Instance;

		FrameBuffer* m_ViewportFrameBuffer;

		std::vector<DrawCallData> m_DrawQueue;

		glm::mat4 m_CurrentViewMatrix;
		glm::mat4 m_CurrentProjectionMatrix;
	};
}