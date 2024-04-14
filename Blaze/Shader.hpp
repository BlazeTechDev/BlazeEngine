#pragma once

#include "Core.hpp"

#include <glm.hpp>

namespace Blaze
{
	enum class BLAZE_API ShaderDataType
	{
		NONE = 0,
		Bool,
		Float,
		Float2,
		Float3,
		Float4,
		Int,
		Int2,
		Int3,
		Int4,
		Double,
		Double2,
		Double3,
		Double4,
		Mat3,
		Mat4
	};

	class BLAZE_API Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		virtual void Bind() const;
		virtual void UnBind() const;

		unsigned int GetID() const { return m_Id; }

		void UploadUniformFloat(const char* variable_name, float value) {};
		void UploadUniformInt() {};
		void UploadUniformDouble() {};
		void UploadUniformMatrix(const char* variable_name, glm::mat4 value);

	protected:
		unsigned int m_Id;
	};
}