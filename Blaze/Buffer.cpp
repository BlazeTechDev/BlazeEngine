#include "blzpch.hpp"
#include "Buffer.hpp"

#include "Graphics.hpp"
#include "OpenGLImpl.hpp"
#include "Application.hpp"
#include "WindowsWindow.hpp"

#include <glad/glad.h>

namespace Blaze
{
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

	void VertexBuffer::UploadData(const std::vector<float>& data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
		}

		m_Data = data;
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

	IndexBuffer::~IndexBuffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteBuffers(1, &m_Id);
		}
	}

	void IndexBuffer::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenBuffers(1, &m_Id);
		}
	}

	void IndexBuffer::UploadData(const std::vector<int>& data)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(int), data.data(), GL_STATIC_DRAW);
		}

		m_Data = data;
	}

	void IndexBuffer::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
		}
	}

	void IndexBuffer::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}
	}

	VertexArray::VertexArray()
	{
		m_Id = 0;
	}

	void VertexArray::Create()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glGenVertexArrays(1, &m_Id);
		}
	}

	void VertexArray::CreateAttributePointer(int index, int size, BlazeDataType data_type, bool normalized, uint32_t stride, uint32_t offset)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glVertexAttribPointer(index, size, OpenGLImpl::GetOpenGLDataType(data_type), normalized ? GL_TRUE : GL_FALSE, stride, (const void*)offset);
		}
	}

	void VertexArray::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(m_Id);
		}
	}

	void VertexArray::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindVertexArray(0);
		}
	}

	void VertexArray::AddVertexBuffer(VertexBuffer& vertexBuffer)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			vertexBuffer.Bind();

			uint32_t index = 0;
			const BufferLayout& layout = vertexBuffer.GetLayout();
			for (const BufferElement element : layout.GetElements())
			{
				Enable(index);
				CreateAttributePointer(index, element.GetElementCount(), ShaderDataTypeToBlazeDataType(element.Type), element.Normalized, layout.GetStride(), element.Offset);
				index++;
			}

			m_VertexBuffers.push_back(vertexBuffer);
		}
	}

	void VertexArray::SetIndexBuffer(IndexBuffer& IndexBuffer)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			Bind();
			IndexBuffer.Bind();

			m_IndexBuffer = IndexBuffer;
		}
	}

	void VertexArray::Enable(int index)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glEnableVertexAttribArray(index);
		}
	}

	void VertexArray::Disable(int index)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDisableVertexAttribArray(index);
		}
	}
	
	FrameBuffer::~FrameBuffer()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glDeleteFramebuffers(1, &m_Id);
		}
	}

	void FrameBuffer::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, m_Id);
		}
	}

	void FrameBuffer::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glBindFramebuffer(GL_FRAMEBUFFER, 0);
		}
	}
	
	void FrameBuffer::Invalidate()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == GraphicsAPIType::OpenGL)
		{
			glCreateFramebuffers(1, &m_Id);
			Bind();

			glCreateTextures(GL_TEXTURE_2D, 1, &m_ColorAttachment);
			glBindTexture(GL_TEXTURE_2D, m_ColorAttachment);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB8, m_Specs.Width, m_Specs.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, nullptr);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_ColorAttachment, 0);

			glCreateTextures(GL_TEXTURE_2D, 1, &m_DepthAttachment);
			glBindTexture(GL_TEXTURE_2D, m_DepthAttachment);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH24_STENCIL8, m_Specs.Width, m_Specs.Height, 0, GL_DEPTH_STENCIL, GL_UNSIGNED_INT_24_8, nullptr);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			BLZ_CORE_ASSERT(glCheckFramebufferStatus(GL_FRAMEBUFFER) == GL_FRAMEBUFFER_COMPLETE, "FrameBuffer is incomplete");

			UnBind();
		}
	}
}