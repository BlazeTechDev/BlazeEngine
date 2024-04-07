#pragma once

#include <imgui.h>

#include "EditorWindow.hpp"
#include "Layer.hpp"
#include "MouseEvent.hpp"
#include "KeyEvent.hpp"
#include "WindowEvent.hpp"


namespace Blaze
{
	class BLAZE_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		
		static ImGuiKey GLFWKeyToImGuiKey(int key);
		static ImGuiKey GLFWMouseButtonToImGuiKey(int button);
		void OnAttach();
		void OnDetach();
		void OnUpdate();
		void OnEvent(Event& event);

		void PushEditorWindow(EditorWindow* editorWindow);
		void PopEditorWindow(EditorWindow* editorWindow);

		void DrawWindows();

	private:
		bool OnWindowResizedEvent(WindowResizedEvent& e);

		std::vector<EditorWindow*> m_EditorWindows;
		std::vector<EditorWindow*>::iterator m_EditorWindowsInsert;

		float m_Time = 0.0f;
	};
}