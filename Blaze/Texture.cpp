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
}