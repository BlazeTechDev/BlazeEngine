#pragma once

#include "Core.hpp"
#include "Layer.hpp"
#include "LayerStack.hpp"
#include "Window.hpp"
#include "WindowEvent.hpp"

namespace Blaze
{
	class BLAZE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
	private:
		bool OnWindowClose(WindowClosedEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// needs to be defined in client app
	Application* CreateApplication();
}