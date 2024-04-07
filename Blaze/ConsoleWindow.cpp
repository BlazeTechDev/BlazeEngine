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

		ImGui::Text("hello world");

		ImGui::End();
	}
}
