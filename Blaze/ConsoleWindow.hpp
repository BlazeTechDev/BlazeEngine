#pragma once

#include "Core.hpp"
#include "EditorWindow.hpp"

namespace Blaze
{
	class BLAZE_API ConsoleWindow : public EditorWindow
	{
	public:
		inline void Update() override;
		inline void Draw() override;

		void Print(const char* text, ...);
		void PrintLine(const char* text, ...);

		const std::string GetCurrentText() { return current_text; }

	private:
		std::string current_text = "console...";
	};
}