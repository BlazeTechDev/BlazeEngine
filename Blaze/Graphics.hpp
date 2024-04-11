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
		static void Initialize(Window* window);
		static void Shutdown();
		static void Update();

		static void SetVSync(bool enabled);

		static void BindSceneViewportFrameBuffer();
		static void UnBindSceneViewportFrameBuffer();

		static FrameBuffer* GetSceneViewportFrameBuffer() { return m_SceneViewportFrameBuffer; }

		const static GraphicsAPIType GetEngineGraphicsAPI() { return m_EngineGraphicsAPI; }
		
	private:
		static FrameBuffer* m_SceneViewportFrameBuffer;
		
		const static GraphicsAPIType m_EngineGraphicsAPI = GraphicsAPIType::OpenGL;
	};
}