#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Entity
	{
	public:
		Entity();
		~Entity();

		Entity* GetParent() { return m_Parent; }
		unsigned int GetID() { return m_Id; }

	private:
		Entity* m_Parent;
		unsigned int m_Id;
	};
}