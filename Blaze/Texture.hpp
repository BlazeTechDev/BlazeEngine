#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Texture
	{
	public:
		~Texture();

		virtual void Create(const int width, const int height);

		void Bind();
		void UnBind();

		int GetWidth() { return m_Width; }
		int GetHeight() { return m_Height; }
		int GetChannels() { return m_Channels; }

		unsigned int GetID() { return m_Id; }

	protected:
		unsigned int m_Id;

		int m_Width;
		int m_Height;
		int m_Channels;
	};
}