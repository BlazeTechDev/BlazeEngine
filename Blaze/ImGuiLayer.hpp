#pragma once

#include <imgui.h>

#include "EditorWindow.hpp"
#include "Layer.hpp"
#include "MouseEvent.hpp"
#include "KeyEvent.hpp"
#include "WindowEvent.hpp"


namespace Blaze
{
	struct ImGuiBlazeTheme
	{
		static constexpr ImVec4 BackgroundColor = ImVec4(0.16f, 0.16f, 0.17f, 1);
		static constexpr ImVec4 DarkPrimary = ImVec4(0.15f, 0.15f, 0.15f, 1);
		static constexpr ImVec4 DarkSecondary = ImVec4(0.11f, 0.11f, 0.11f, 1);
		static constexpr ImVec4 LightPrimary = ImVec4(0.24f, 0.24f, 0.24f, 1);
		static constexpr ImVec4 RedPrimary = ImVec4(0.94f, 0.24f, 0.24f, 255);
		static constexpr ImVec4 RedSecondary = ImVec4(1, 0.33f, 0.33f, 1);
	};

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

		void LoadImGuiStyles();

		void DrawWindows();

	private:
		bool OnWindowResizedEvent(WindowResizedEvent& e);

		std::vector<EditorWindow*> m_EditorWindows;
		std::vector<EditorWindow*>::iterator m_EditorWindowsInsert;

		float m_Time = 0.0f;
	};
}