#include "blzpch.hpp"

#include "ImGuiLayer.hpp"
#include "Application.hpp"
#include "Event.hpp"
#include "WindowsWindow.hpp"
#include "imgui_impl_opengl3.h"
#include "imgui_impl_glfw.h"
#include "Core.hpp"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace Blaze
{
	ImGuiLayer::ImGuiLayer() : Layer("ImGuiLayer") 
    {
        m_EditorWindowsInsert = m_EditorWindows.begin();
    }
	ImGuiLayer::~ImGuiLayer() {};

    ImGuiKey ImGuiLayer::GLFWKeyToImGuiKey(int key)
    {
        switch (key)
        {
        case GLFW_KEY_TAB: return ImGuiKey_Tab;
        case GLFW_KEY_LEFT: return ImGuiKey_LeftArrow;
        case GLFW_KEY_RIGHT: return ImGuiKey_RightArrow;
        case GLFW_KEY_UP: return ImGuiKey_UpArrow;
        case GLFW_KEY_DOWN: return ImGuiKey_DownArrow;
        case GLFW_KEY_PAGE_UP: return ImGuiKey_PageUp;
        case GLFW_KEY_PAGE_DOWN: return ImGuiKey_PageDown;
        case GLFW_KEY_HOME: return ImGuiKey_Home;
        case GLFW_KEY_END: return ImGuiKey_End;
        case GLFW_KEY_INSERT: return ImGuiKey_Insert;
        case GLFW_KEY_DELETE: return ImGuiKey_Delete;
        case GLFW_KEY_BACKSPACE: return ImGuiKey_Backspace;
        case GLFW_KEY_SPACE: return ImGuiKey_Space;
        case GLFW_KEY_ENTER: return ImGuiKey_Enter;
        case GLFW_KEY_ESCAPE: return ImGuiKey_Escape;
        case GLFW_KEY_APOSTROPHE: return ImGuiKey_Apostrophe;
        case GLFW_KEY_COMMA: return ImGuiKey_Comma;
        case GLFW_KEY_MINUS: return ImGuiKey_Minus;
        case GLFW_KEY_PERIOD: return ImGuiKey_Period;
        case GLFW_KEY_SLASH: return ImGuiKey_Slash;
        case GLFW_KEY_SEMICOLON: return ImGuiKey_Semicolon;
        case GLFW_KEY_EQUAL: return ImGuiKey_Equal;
        case GLFW_KEY_LEFT_BRACKET: return ImGuiKey_LeftBracket;
        case GLFW_KEY_BACKSLASH: return ImGuiKey_Backslash;
        case GLFW_KEY_RIGHT_BRACKET: return ImGuiKey_RightBracket;
        case GLFW_KEY_GRAVE_ACCENT: return ImGuiKey_GraveAccent;
        case GLFW_KEY_CAPS_LOCK: return ImGuiKey_CapsLock;
        case GLFW_KEY_SCROLL_LOCK: return ImGuiKey_ScrollLock;
        case GLFW_KEY_NUM_LOCK: return ImGuiKey_NumLock;
        case GLFW_KEY_PRINT_SCREEN: return ImGuiKey_PrintScreen;
        case GLFW_KEY_PAUSE: return ImGuiKey_Pause;
        case GLFW_KEY_KP_0: return ImGuiKey_Keypad0;
        case GLFW_KEY_KP_1: return ImGuiKey_Keypad1;
        case GLFW_KEY_KP_2: return ImGuiKey_Keypad2;
        case GLFW_KEY_KP_3: return ImGuiKey_Keypad3;
        case GLFW_KEY_KP_4: return ImGuiKey_Keypad4;
        case GLFW_KEY_KP_5: return ImGuiKey_Keypad5;
        case GLFW_KEY_KP_6: return ImGuiKey_Keypad6;
        case GLFW_KEY_KP_7: return ImGuiKey_Keypad7;
        case GLFW_KEY_KP_8: return ImGuiKey_Keypad8;
        case GLFW_KEY_KP_9: return ImGuiKey_Keypad9;
        case GLFW_KEY_KP_DECIMAL: return ImGuiKey_KeypadDecimal;
        case GLFW_KEY_KP_DIVIDE: return ImGuiKey_KeypadDivide;
        case GLFW_KEY_KP_MULTIPLY: return ImGuiKey_KeypadMultiply;
        case GLFW_KEY_KP_SUBTRACT: return ImGuiKey_KeypadSubtract;
        case GLFW_KEY_KP_ADD: return ImGuiKey_KeypadAdd;
        case GLFW_KEY_KP_ENTER: return ImGuiKey_KeypadEnter;
        case GLFW_KEY_KP_EQUAL: return ImGuiKey_KeypadEqual;
        case GLFW_KEY_LEFT_SHIFT: return ImGuiKey_LeftShift;
        case GLFW_KEY_LEFT_CONTROL: return ImGuiKey_LeftCtrl;
        case GLFW_KEY_LEFT_ALT: return ImGuiKey_LeftAlt;
        case GLFW_KEY_LEFT_SUPER: return ImGuiKey_LeftSuper;
        case GLFW_KEY_RIGHT_SHIFT: return ImGuiKey_RightShift;
        case GLFW_KEY_RIGHT_CONTROL: return ImGuiKey_RightCtrl;
        case GLFW_KEY_RIGHT_ALT: return ImGuiKey_RightAlt;
        case GLFW_KEY_RIGHT_SUPER: return ImGuiKey_RightSuper;
        case GLFW_KEY_MENU: return ImGuiKey_Menu;
        case GLFW_KEY_0: return ImGuiKey_0;
        case GLFW_KEY_1: return ImGuiKey_1;
        case GLFW_KEY_2: return ImGuiKey_2;
        case GLFW_KEY_3: return ImGuiKey_3;
        case GLFW_KEY_4: return ImGuiKey_4;
        case GLFW_KEY_5: return ImGuiKey_5;
        case GLFW_KEY_6: return ImGuiKey_6;
        case GLFW_KEY_7: return ImGuiKey_7;
        case GLFW_KEY_8: return ImGuiKey_8;
        case GLFW_KEY_9: return ImGuiKey_9;
        case GLFW_KEY_A: return ImGuiKey_A;
        case GLFW_KEY_B: return ImGuiKey_B;
        case GLFW_KEY_C: return ImGuiKey_C;
        case GLFW_KEY_D: return ImGuiKey_D;
        case GLFW_KEY_E: return ImGuiKey_E;
        case GLFW_KEY_F: return ImGuiKey_F;
        case GLFW_KEY_G: return ImGuiKey_G;
        case GLFW_KEY_H: return ImGuiKey_H;
        case GLFW_KEY_I: return ImGuiKey_I;
        case GLFW_KEY_J: return ImGuiKey_J;
        case GLFW_KEY_K: return ImGuiKey_K;
        case GLFW_KEY_L: return ImGuiKey_L;
        case GLFW_KEY_M: return ImGuiKey_M;
        case GLFW_KEY_N: return ImGuiKey_N;
        case GLFW_KEY_O: return ImGuiKey_O;
        case GLFW_KEY_P: return ImGuiKey_P;
        case GLFW_KEY_Q: return ImGuiKey_Q;
        case GLFW_KEY_R: return ImGuiKey_R;
        case GLFW_KEY_S: return ImGuiKey_S;
        case GLFW_KEY_T: return ImGuiKey_T;
        case GLFW_KEY_U: return ImGuiKey_U;
        case GLFW_KEY_V: return ImGuiKey_V;
        case GLFW_KEY_W: return ImGuiKey_W;
        case GLFW_KEY_X: return ImGuiKey_X;
        case GLFW_KEY_Y: return ImGuiKey_Y;
        case GLFW_KEY_Z: return ImGuiKey_Z;
        case GLFW_KEY_F1: return ImGuiKey_F1;
        case GLFW_KEY_F2: return ImGuiKey_F2;
        case GLFW_KEY_F3: return ImGuiKey_F3;
        case GLFW_KEY_F4: return ImGuiKey_F4;
        case GLFW_KEY_F5: return ImGuiKey_F5;
        case GLFW_KEY_F6: return ImGuiKey_F6;
        case GLFW_KEY_F7: return ImGuiKey_F7;
        case GLFW_KEY_F8: return ImGuiKey_F8;
        case GLFW_KEY_F9: return ImGuiKey_F9;
        case GLFW_KEY_F10: return ImGuiKey_F10;
        case GLFW_KEY_F11: return ImGuiKey_F11;
        case GLFW_KEY_F12: return ImGuiKey_F12;
        default: return ImGuiKey_None;
        }
    }

    ImGuiKey ImGuiLayer::GLFWMouseButtonToImGuiKey(int button)
    {
        switch (button)
        {
        case GLFW_MOUSE_BUTTON_LEFT: return ImGuiKey_MouseLeft;
        case GLFW_MOUSE_BUTTON_RIGHT: return ImGuiKey_MouseRight;
        case GLFW_MOUSE_BUTTON_MIDDLE: return ImGuiKey_MouseMiddle;
        default: return ImGuiKey_None;
        }
    }

	void ImGuiLayer::OnAttach()
	{
		ImGui::CreateContext();

        LoadImGuiStyles();

		ImGuiIO& io = ImGui::GetIO();
		io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
		io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
		io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       // Enable Keyboard Controls
		io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;           // Enable Docking
		io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;         // Enable Multi-Viewport / Platform Windows

		ImGui_ImplOpenGL3_Init("#version 410");
        WindowsWindow& window = (WindowsWindow&)Application::Get().GetWindow();
        ImGui_ImplGlfw_InitForOpenGL(window.m_Window, true);
	}

	void ImGuiLayer::OnDetach()
	{
        for (EditorWindow* editorWindow : m_EditorWindows)
        {
            delete editorWindow;
        }
	}

	void ImGuiLayer::OnUpdate()
	{
		ImGuiIO& io = ImGui::GetIO();
		Application& app = Application::Get();
		io.DisplaySize = ImVec2(app.GetWindow().GetWidth(), app.GetWindow().GetHeight());

        glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
	
        ImGui::NewFrame();

        ImVec2 workCenter = ImGui::GetMainViewport()->GetWorkCenter();
        ImVec2 size{ (float)Application::Get().GetWindow().GetWidth(), (float)Application::Get().GetWindow().GetHeight() };
        ImVec2 pos{ workCenter.x - size.x * 0.5f, workCenter.y - size.y * 0.5f };


        ImGui::SetNextWindowPos(pos);
        ImGui::SetNextWindowSize(size);
        ImGui::SetNextWindowViewport(ImGui::GetMainViewport()->ID);

        static bool open_window = true;
        ImGui::Begin("Dockspace", &open_window, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoNavFocus | ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoResize);
        ImGui::DockSpace(ImGui::GetID("Dockspace"), ImVec2(0,0), ImGuiDockNodeFlags_PassthruCentralNode);

        ImGui::End();

        DrawWindows();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

		ImGui::Render();
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            GLFWwindow* backup_current_context = glfwGetCurrentContext();
            ImGui::UpdatePlatformWindows();
            ImGui::RenderPlatformWindowsDefault();
            glfwMakeContextCurrent(backup_current_context);
        }
	}

    void ImGuiLayer::DrawWindows()
    {
        for (EditorWindow* editorWindow : m_EditorWindows)
        {
            editorWindow->Draw();
        }
    }

	void ImGuiLayer::OnEvent(Event& event)
	{
		EventDispatcher dispatcher(event);
		dispatcher.Dispatch<WindowResizedEvent>(BLZ_BIND_EVENT_FN(ImGuiLayer::OnWindowResizedEvent));
	}

    void ImGuiLayer::PushEditorWindow(EditorWindow* editorWindow)
    {
        m_EditorWindowsInsert = m_EditorWindows.emplace(m_EditorWindowsInsert, editorWindow);
    }

    void ImGuiLayer::PopEditorWindow(EditorWindow* editorWindow)
    {
        auto it = std::find(m_EditorWindows.begin(), m_EditorWindows.end(), editorWindow);
        if (it != m_EditorWindows.end())
        {
            m_EditorWindows.erase(it);
            m_EditorWindowsInsert--;
        }
    }

    void ImGuiLayer::LoadImGuiStyles()
    {
        ImGuiStyle& style = ImGui::GetStyle();
        
        style.Colors[ImGuiCol_WindowBg] = ImGuiBlazeTheme::BackgroundColor;
        style.Colors[ImGuiCol_TitleBgActive] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_TitleBg] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_Border] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_Separator] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_SeparatorHovered] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_SeparatorActive] = ImGuiBlazeTheme::RedSecondary;
        style.Colors[ImGuiCol_FrameBg] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_FrameBgHovered] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_FrameBgActive] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_Header] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_HeaderHovered] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_HeaderActive] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_Button] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_ButtonHovered] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_ButtonActive] = ImGuiBlazeTheme::DarkPrimary;
        style.Colors[ImGuiCol_SliderGrab] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_SliderGrabActive] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_CheckMark] = ImGuiBlazeTheme::RedSecondary;
        style.Colors[ImGuiCol_ResizeGrip] = ImGuiBlazeTheme::RedSecondary;
        style.Colors[ImGuiCol_ResizeGripHovered] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_ResizeGripActive] = ImGuiBlazeTheme::RedSecondary;
        style.Colors[ImGuiCol_Tab] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_TabActive] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_TabHovered] = ImGuiBlazeTheme::LightPrimary;
        style.Colors[ImGuiCol_TabUnfocused] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_TabUnfocusedActive] = ImGuiBlazeTheme::DarkSecondary;
        style.Colors[ImGuiCol_NavHighlight] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_DockingPreview] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_PlotHistogram] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImGuiBlazeTheme::RedSecondary;
        style.Colors[ImGuiCol_PlotLines] = ImGuiBlazeTheme::RedPrimary;
        style.Colors[ImGuiCol_PlotLinesHovered] = ImGuiBlazeTheme::RedSecondary;

        style.ChildRounding = 3;
        style.FrameRounding = 0;
        style.GrabRounding = 2;
        style.PopupRounding = 3;
        style.TabRounding = 0;
        style.WindowRounding = 0;

        style.FrameBorderSize = 1;

        style.WindowPadding = ImVec2(3, 3);
    }

	bool ImGuiLayer::OnWindowResizedEvent(WindowResizedEvent& e)
	{
		glViewport(0, 0, e.GetWidth(), e.GetHeight());

		return false;
	}
}