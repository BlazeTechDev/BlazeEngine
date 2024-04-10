#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"

namespace Blaze
{
	FrameBuffer::FrameBuffer() : Buffer()
	{
		glGenFramebuffers(1, &m_Id);
	}

	FrameBuffer::~FrameBuffer()
	{
		glDeleteFramebuffers(1, &m_Id);
	}

	void FrameBuffer::Bind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, m_Id);
		}
	}

	void FrameBuffer::UnBind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, 0);
		}
	}
}