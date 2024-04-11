#pragma once

#include "Entity.hpp"
#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Component
	{
	public:
		Component();
		~Component();

		Entity* GetEntity() { return m_Entity; }

	private:
		Entity* m_Entity;
	};
}