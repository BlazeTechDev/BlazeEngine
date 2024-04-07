#pragma once

#include <GLFW/glfw3.h>

#include "Window.hpp"

namespace Blaze
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }
		inline std::string GetTitle() const override{ return m_Data.Title; }
		inline void* GetData() const override { return (void*)&m_Data; }

		inline void SetEventCallback(const EventCallbackFn& callback) override { m_Data.EventCallback = callback; }
		void SetVSync(bool enabled);
		bool IsVSync() const;

		GLFWwindow* m_Window;

	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();

		WindowData m_Data;
	};
}