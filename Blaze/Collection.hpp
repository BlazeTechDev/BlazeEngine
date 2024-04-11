#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Collection
	{
	public:
		Collection(std::string name);
		~Collection();

		void Start();

		void EditorTick();
		void Tick();

		std::string GetCollectionName() { return m_Name; }

	private:
		void DrawCollection();

		std::string m_Name;
	};
}