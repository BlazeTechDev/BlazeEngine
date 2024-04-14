#include "blzpch.hpp"
#include "SceneViewport.hpp"

#include "Graphics.hpp"
#include <imgui.h>

namespace Blaze
{
	void SceneViewport::Update()
	{

	}

	void SceneViewport::Draw()
	{
		if (ImGui::Begin("Scene Viewport"))
		{
			FrameBuffer* ViewportFrameBuffer = Graphics::Get()->GetViewportFrameBuffer();
			ImGui::Image((void*)ViewportFrameBuffer->GetColorAttachment(), ImVec2(ImGui::GetWindowWidth(), ImGui::GetWindowHeight() - 25));
		}
		ImGui::End();
	}
}