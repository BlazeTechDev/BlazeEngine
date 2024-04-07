#pragma once

#include "Core.hpp"
#include "EditorWindow.hpp"

namespace Blaze
{
	class BLAZE_API ConsoleWindow : public EditorWindow
	{
		inline void Update() override;
		inline void Draw() override;
	};
}