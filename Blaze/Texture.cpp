#include "blzpch.hpp"
#include "Texture.hpp"

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

		glGenTextures(1, &m_Id);
		Bind();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, (void*)0);
		glGenerateMipmap(GL_TEXTURE_2D);
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, m_Id);
	}

	void Texture::UnBind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}