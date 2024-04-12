#include "blzpch.hpp"
#include "Shader.hpp"
#include "Log.hpp"

#include <glad/glad.h>

namespace Blaze
{
	Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
	{
		m_Id = 0;

		// Create an empty vertex shader handle
		GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);

		// Send the vertex shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		const GLchar* source = (const GLchar*)vertexSource.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		// Compile the vertex shader
		glCompileShader(vertexShader);

		GLint isCompiled = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Vertex Shader error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");

			// We don't need the shader anymore.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Create an empty fragment shader handle
		GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		// Send the fragment shader source code to GL
		// Note that std::string's .c_str is NULL character terminated.
		source = (const GLchar*)fragmentSource.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		// Compile the fragment shader
		glCompileShader(fragmentShader);

		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &isCompiled);
		if (isCompiled == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Fragment Shader error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");
			// We don't need the shader anymore.
			glDeleteShader(fragmentShader);
			// Either of them. Don't leak shaders.
			glDeleteShader(vertexShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Vertex and fragment shaders are successfully compiled.
		// Now time to link them together into a program.
		// Get a program object.

		m_Id = glCreateProgram();

		// Attach our shaders to our program
		glAttachShader(m_Id, vertexShader);
		glAttachShader(m_Id, fragmentShader);

		// Link our program
		glLinkProgram(m_Id);

		// Note the different functions here: glGetProgram* instead of glGetShader*.
		GLint isLinked = 0;
		glGetProgramiv(m_Id, GL_LINK_STATUS, (int*)&isLinked);
		if (isLinked == GL_FALSE)
		{
			GLint maxLength = 0;
			glGetProgramiv(m_Id, GL_INFO_LOG_LENGTH, &maxLength);

			// The maxLength includes the NULL character
			std::vector<GLchar> infoLog(maxLength);
			glGetProgramInfoLog(m_Id, maxLength, &maxLength, &infoLog[0]);

			BLZ_CORE_ERROR("Shader Program error: {0}", infoLog.data());
			BLZ_CORE_ASSERT(false, "Shader link failure");

			// We don't need the program anymore.
			glDeleteProgram(m_Id);
			// Don't leak shaders either.
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			// Use the infoLog as you see fit.

			// In this simple program, we'll just leave
			return;
		}

		// Always detach shaders after a successful link.
		glDetachShader(m_Id, vertexShader);
		glDetachShader(m_Id, fragmentShader);
	}

	Shader::~Shader()
	{
		glDeleteProgram(m_Id);
	}

	void Shader::Bind() const
	{
		glUseProgram(m_Id);
	}

	void Shader::UnBind() const
	{
		glUseProgram(0);
	}
}