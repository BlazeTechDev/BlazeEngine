#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Shader
	{
	public:
		Shader(const std::string& vertexSource, const std::string& fragmentSource);
		~Shader();

		virtual void Bind() const;
		virtual void UnBind() const;

		unsigned int GetID() const { return m_Id; }

	protected:
		unsigned int m_Id;
	};
}