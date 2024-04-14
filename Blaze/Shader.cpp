#include "blzpch.hpp"
#include "Shader.hpp"
#include "Log.hpp"
#include "Graphics.hpp"
#include "OpenGLImpl.hpp"

#include <gtc/type_ptr.hpp>
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
	
	void Shader::UploadUniformMatrix(const char* variable_name, glm::mat4& value)
	{
		int location = glGetUniformLocation(m_Id, variable_name);
		glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(value));
	}
}