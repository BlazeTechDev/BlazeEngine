#pragma once

#include "Core.hpp"
#include "Window.hpp"

namespace Blaze
{
	class BLAZE_API Graphics
	{
	public:
		static void Initialize(Window* window);
		static void Shutdown();
		static void Update();

		static void SetVSync(bool enabled);
	};
}