#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"
#include "OpenGLImpl.hpp"

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
			glBufferData(GL_ARRAY_BUFFER, data->size() * sizeof(float), data->data(), GL_STATIC_DRAW);
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

	void ElementBuffer::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	void ElementBuffer::UploadData(std::vector<int>* data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->size() * sizeof(int), data->data(), GL_STATIC_DRAW);
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

	void AttributeArray::CreateAttributePointer(int index, int size, BlazeDataType data_type, size_t data_type_size)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glVertexAttribPointer(index, size, OpenGLImpl::GetOpenGLDataType(data_type), GL_FALSE, size * data_type_size, (void*)0);
		}
	}

	void AttributeArray::Bind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(m_Id);
		}
	}

	void AttributeArray::UnBind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(0);
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