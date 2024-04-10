#pragma once

#include "Core.hpp"
#include "Window.hpp"

namespace Blaze
{
	enum BLAZE_API GraphicsAPIType
	{
		OpenGL = 0,
		Vulkan = 1,
		Metal = 2,
		DirectX = 3
	};

	struct BLAZE_API AgnosticFrameBuffer
	{
		unsigned int OpenGLFrameBuffer;
	};

	class BLAZE_API Graphics
	{
	public:
		static void Initialize(Window* window);
		static void Shutdown();
		static void Update();

		static void SetVSync(bool enabled);

		const static GraphicsAPIType GetEngineGraphicsAPI() { return m_EngineGraphicsAPI; }
			
	private:
		const static GraphicsAPIType m_EngineGraphicsAPI = GraphicsAPIType::OpenGL;
	};
}