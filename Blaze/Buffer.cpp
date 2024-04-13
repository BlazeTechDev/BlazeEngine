#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"
#include "OpenGLImpl.hpp"

#include <glad/glad.h>

namespace Blaze
{
	VertexBuffer::VertexBuffer() : Buffer()
	{
		m_Layout = nullptr;
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

	void VertexBuffer::UploadData(const std::vector<float>* data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			glBufferData(GL_ARRAY_BUFFER, data->size() * sizeof(float), data->data(), GL_STATIC_DRAW);
		}
	}

	void VertexBuffer::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_Id);
		}
	}

	void VertexBuffer::UnBind() const
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

	void ElementBuffer::UploadData(const std::vector<int>* data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, data->size() * sizeof(int), data->data(), GL_STATIC_DRAW);
		}
	}

	void ElementBuffer::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		}
	}

	void ElementBuffer::UnBind() const
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

	void FrameBuffer::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, m_Id);
		}
	}

	void FrameBuffer::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_FRAMEBUFFER, 0);
		}
	}

	AttributeArray::AttributeArray()
	{
		m_Id = 0;
	}

	void AttributeArray::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenVertexArrays(1, &m_Id);
		}
	}

	void AttributeArray::CreateAttributePointer(int index, int size, BlazeDataType data_type, bool normalized, uint32_t stride, uint32_t offset)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glVertexAttribPointer(index, size, OpenGLImpl::GetOpenGLDataType(data_type), normalized ? GL_TRUE : GL_FALSE, stride, (const void*)offset);
		}
	}

	void AttributeArray::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(m_Id);
		}
	}

	void AttributeArray::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(0);
		}
	}

	void AttributeArray::AddVertexBuffer(VertexBuffer* vertexBuffer)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			vertexBuffer->Bind();

			uint32_t index = 0;
			const BufferLayout* layout = vertexBuffer->GetLayout();
			for (const BufferElement element : layout->GetElements())
			{
				Enable(index);
				CreateAttributePointer(index, element.GetElementCount(), ShaderDataTypeToBlazeDataType(element.Type), element.Normalized, layout->GetStride(), element.Offset);
				index++;
			}

			m_VertexBuffers.push_back(vertexBuffer);
		}
	}

	void AttributeArray::SetElementBuffer(ElementBuffer* elementBuffer)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			elementBuffer->Bind();

			m_ElementBuffer = elementBuffer;
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