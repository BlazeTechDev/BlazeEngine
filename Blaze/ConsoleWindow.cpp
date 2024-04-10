#include "blzpch.hpp"
#include "ConsoleWindow.hpp"

#include <imgui.h>

namespace Blaze
{
	inline void ConsoleWindow::Update()
	{

	}

	void ConsoleWindow::Draw()
	{
		ImGui::Begin("Console");

		ImGui::Text(current_text.c_str());

		ImGui::End();
	}

	void ConsoleWindow::Print(const char* text, ...)
	{
		current_text = text;
	}

	void ConsoleWindow::PrintLine(const char* text, ...)
	{
		current_text = text;
		current_text.append("\n");
	}
}
