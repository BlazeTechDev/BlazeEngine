#pragma once

#include "Event.hpp"
#include "Versions.hpp"

namespace Blaze
{
	struct WindowProps
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "Blaze Engine v" + ENGINE_VERSION,
			unsigned int width = 1280,
			unsigned int height = 720) 
			: Title(title), Width(width), Height(height) {}
	};

	using EventCallbackFn = std::function<void(Event&)>;

	struct WindowData
	{
		std::string Title;
		unsigned int Width;
		unsigned int Height;
		bool VSync;

		EventCallbackFn EventCallback;
	};

	// interface representing a window that does not belong to any platform (must be implemented per platform)
	class BLAZE_API Window
	{
	public:
		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;
		virtual std::string GetTitle() const = 0;
		virtual void* GetData() const = 0;

		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}