#include "blzpch.hpp"

#include "ApplicationEvent.hpp"
#include "WindowEvent.hpp"
#include "KeyEvent.hpp"
#include "MouseEvent.hpp"
#include "WindowsWindow.hpp"
#include "Core.hpp"
#include "Log.hpp"

#include "Graphics.hpp"

#include <glad/glad.h>

namespace Blaze
{
	Window* Window::Create(const WindowProps& props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{

	}

	void WindowsWindow::Init(const WindowProps& props)
	{
		m_Data.Title = props.Title;
		m_Data.Width = props.Width;
		m_Data.Height = props.Height;

		BLZ_CORE_INFO("creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		Graphics::Get()->Initialize(this);
	}

	void WindowsWindow::Shutdown()
	{
		Graphics::Get()->Shutdown();
	}

	void WindowsWindow::OnUpdate()
	{
		Graphics::Get()->Update();
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		Graphics::Get()->SetVSync(enabled);
		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}
}
