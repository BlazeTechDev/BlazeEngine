#include "blzpch.hpp"

#include "Application.hpp"

#include "WindowEvent.hpp"
#include "Log.hpp"

namespace Blaze
{
	Application::Application()
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		while (m_Running)
		{
			m_Window->OnUpdate();
		}
	}
}