#pragma once

#include "Core.hpp"
#include "Window.hpp"

namespace Blaze
{
	class BLAZE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// needs to be defined in client app
	Application* CreateApplication();
}