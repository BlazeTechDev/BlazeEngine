#pragma once

#include "Core.hpp"
#include "EditorWindow.hpp"

namespace Blaze
{
	class BLAZE_API CollectionWindow : public EditorWindow
	{
		virtual void Update();
		virtual void Draw();
	};
}