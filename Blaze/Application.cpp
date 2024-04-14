#include <GLFW/glfw3.h>

#include "blzpch.hpp"

#include "Application.hpp"
#include "WindowEvent.hpp"
#include "Log.hpp"
#include "Core.hpp"
#include "Tick.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Blaze
{
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		BLZ_CORE_ASSERT(!s_Instance, "application already exists");
		s_Instance = this;

		m_Graphics = new Graphics();

		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BLZ_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application()
	{
		delete m_Graphics;
	}

	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowClosedEvent>(BLZ_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
			{
				break;
			}
		}
	}

	void Application::Run()
	{
		while (m_Running)
		{
			float time = glfwGetTime();
			Timestep timeStep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			Tick::TickOnce(timeStep);

			for (Layer* layer : m_LayerStack)
			{
				layer->OnUpdate(timeStep);
			}

			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowClosedEvent& e)
	{
		m_Running = false;
		return true;
	}
}