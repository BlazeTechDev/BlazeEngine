#include "blzpch.hpp"
#include "PropertiesWindow.hpp"

#include <imgui.h>

namespace Blaze
{
	void PropertiesWindow::Update()
	{

	}

	void PropertiesWindow::Draw()
	{
		ImGui::Begin("Properties Window");

		ImGui::Button("Add MetaData");

		ImGui::SameLine();

		char* text_buffer = "";
		ImGui::InputText("Search", text_buffer, sizeof(char) * 10);

		ImGui::End();
	}
}