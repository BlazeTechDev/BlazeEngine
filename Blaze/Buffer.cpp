#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"

#include <glad/glad.h>

namespace Blaze
{
	VertexBuffer::VertexBuffer() : Buffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	VertexBuffer::~VertexBuffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteBuffers(1, &m_Id);
		}
	}

	void VertexBuffer::Bind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}
	}

	void VertexBuffer::UnBind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}

	ElementBuffer::ElementBuffer() : Buffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	ElementBuffer::~ElementBuffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteBuffers(1, &m_Id);
		}
	}

	void ElementBuffer::Bind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		}
	}

	void ElementBuffer::UnBind()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}

	FrameBuffer::FrameBuffer() : Buffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenFramebuffers(1, &m_Id);
		}
	}

	FrameBuffer::~FrameBuffer()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteFramebuffers(1, &m_Id);
		}
	}

	bool FrameBuffer::IsFrameBufferComplete()
	{
		if (Graphics::GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
			{
				return true;
			}
		}

		return false;
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