#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// needs to be defined in client app
	Application* CreateApplication();
}