#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Texture
	{
	public:
		void Create() {};

		void Bind() {};
		void UnBind() {};

		unsigned int GetID() { return m_Id; }

	protected:
		unsigned int m_Id;
	};
}