#pragma once

#include "Core.hpp"
#include "Window.hpp"
#include "Buffer.hpp"

namespace Blaze
{
	enum BLAZE_API GraphicsAPIType
	{
		OpenGL = 0,
		Vulkan = 1,
		Metal = 2,
		DirectX = 3
	};

	class BLAZE_API Graphics
	{
	public:
		Graphics();

		void Initialize(Window* window);
		void Shutdown();
		void Update();

		void SetVSync(bool enabled);

		void BindSceneViewportFrameBuffer();
		void UnBindSceneViewportFrameBuffer();

		FrameBuffer* GetSceneViewportFrameBuffer() { return m_SceneViewportFrameBuffer; }

		const GraphicsAPIType GetEngineGraphicsAPI() { return m_EngineGraphicsAPI; }

		static Graphics* Get() { return s_Instance; }
		
	private:
		FrameBuffer* m_SceneViewportFrameBuffer;
		
		const static GraphicsAPIType m_EngineGraphicsAPI = GraphicsAPIType::OpenGL;

		static Graphics* s_Instance;
	};
}