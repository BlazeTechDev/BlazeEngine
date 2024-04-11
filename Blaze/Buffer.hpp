#pragma once

#include "Core.hpp"

namespace Blaze
{
	class BLAZE_API Buffer
	{
	public:
		Buffer() { m_Id = 0; };
		~Buffer() {};

		virtual void Bind() {};
		virtual void UnBind() {};

		unsigned int GetId() { return m_Id; }

	protected:
		unsigned int m_Id;
	};

	class BLAZE_API VertexBuffer : public Buffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;
	};

	class BLAZE_API ElementBuffer : public Buffer
	{
	public:
		ElementBuffer();
		~ElementBuffer();

		virtual void Bind() override;
		virtual void UnBind() override;
	};

	class BLAZE_API FrameBuffer : public Buffer
	{
	public:
		FrameBuffer();
		~FrameBuffer();

		bool IsFrameBufferComplete();

		virtual void Bind() override;
		virtual void UnBind() override;
	};
}