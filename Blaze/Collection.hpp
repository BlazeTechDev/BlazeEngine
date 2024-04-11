#pragma once

#include "Core.hpp"
#include "Entity.hpp"
#include "Component.hpp"

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

		std::vector<Entity*> m_Entities;
		std::vector<Component*> m_Components;

		std::string m_Name;
	};
}