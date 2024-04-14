#include "blzpch.hpp"
#include "Texture.hpp"
#include "Graphics.hpp"

#include <glad/glad.h>

namespace Blaze
{
	Texture::~Texture()
	{
		glDeleteTextures(1, &m_Id);
	}

	void Texture::Create(const int width, const int height)
	{
		m_Width = width;
		m_Height = height;

		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glGenTextures(1, &m_Id);
		}
	}

	void Texture::Bind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glBindTexture(GL_TEXTURE_2D, m_Id);
		}
	}

	void Texture::UnBind()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glBindTexture(GL_TEXTURE_2D, 0);
		}
	}

	void FrameBufferTexture::Create(const int width, const int height)
	{
		m_Width = width;
		m_Height = height;
		m_Channels = GL_RGB;

		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glGenTextures(1, &m_Id);
			glTexImage2D(GL_TEXTURE_2D, 0, m_Channels, m_Width, m_Height, 0, m_Channels, GL_UNSIGNED_BYTE, NULL);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}
}