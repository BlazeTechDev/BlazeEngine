#include "blzpch.hpp"
#include "Shader.hpp"
#include "Log.hpp"
#include "Graphics.hpp"
#include "OpenGLImpl.hpp"

#include <glad/glad.h>

namespace Blaze
{
	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			m_Id = OpenGLImpl::CreateOpenGLShader(vertexSource, fragmentSource);
		}
	}

	Shader::~Shader()
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glDeleteProgram(m_Id);
		}
	}

	void Shader::Bind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glUseProgram(m_Id);
		}
	}

	void Shader::UnBind() const
	{
		if (Graphics::Get()->GetEngineGraphicsAPI() == OpenGL)
		{
			glUseProgram(0);
		}
	}
}