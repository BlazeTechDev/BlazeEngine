#pragma once

#include "Core.hpp"

#include <glad/glad.h>

namespace Blaze
{
	class BLAZE_API Buffer
	{
	public:
		Buffer() { m_Id = 0; };
		~Buffer() {};

		virtual void Bind() {};
		virtual void UnBind() {};

		unsigned int GetId() { return m_Id; }

	protected:
		unsigned int m_Id;
	};

	class BLAZE_API FrameBuffer : public Buffer
	{
	public:
		FrameBuffer();
		~FrameBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;
	};
}