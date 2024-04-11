#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"

#include <glad/glad.h>

namespace Blaze
{
	VertexBuffer::VertexBuffer() : Buffer()
	{
		
	}

	VertexBuffer::~VertexBuffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteBuffers(1, &m_Id);
		}
	}

	void VertexBuffer::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	void VertexBuffer::UploadData(std::vector<float>* data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			glBufferData(GL_ARRAY_BUFFER, data->size() * sizeof(float), data, GL_STATIC_DRAW);
			UnBind();
		}
	}

	void VertexBuffer::Bind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}
	}

	void VertexBuffer::UnBind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
	}

	ElementBuffer::ElementBuffer() : Buffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	ElementBuffer::~ElementBuffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteBuffers(1, &m_Id);
		}
	}

	void ElementBuffer::Bind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		}
	}

	void ElementBuffer::UnBind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}

	FrameBuffer::FrameBuffer() : Buffer()
	{
		
	}

	FrameBuffer::~FrameBuffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteFramebuffers(1, &m_Id);
		}
	}

	bool FrameBuffer::IsFrameBufferComplete()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			if (glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE)
			{
				return true;
			}
		}

		return false;
	}

	void FrameBuffer::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenFramebuffers(1, &m_Id);
		}
	}

	void FrameBuffer::Bind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, m_Id);
		}
	}

	void FrameBuffer::UnBind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, 0);
		}
	}

	void AttributeArray::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenVertexArrays(1, &m_Id);
		}
	}

	void AttributeArray::Enable(int index)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glEnableVertexAttribArray(index);
		}
	}

	void AttributeArray::Disable(int index)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDisableVertexAttribArray(index);
		}
	}
}