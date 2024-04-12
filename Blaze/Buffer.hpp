#pragma once

#include "Core.hpp"

namespace Blaze
{
	enum BLAZE_API BlazeDataType
	{
		BLZ_FLOAT,
		BLZ_INT,
		BLZ_DOUBLE,
	};

	class BLAZE_API AttributeArray
	{
	public:
		AttributeArray() { m_Id = 0; }

		void Create();

		void CreateAttributePointer(int index, int size, BlazeDataType data_type, size_t data_type_size);

		void Bind();
		void UnBind();

		void Enable(int indeex);
		void Disable(int index);

		unsigned int GetID() { return m_Id; }

	private:
		unsigned int m_Id;
	};

	class BLAZE_API Buffer
	{
	public:
		Buffer() { m_Id = 0; };
		~Buffer() {};

		virtual void Create() {};

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

		virtual void Create() override;

		void UploadData(std::vector<float>* data);

		virtual void Bind() override;
		virtual void UnBind() override;
	};

	class BLAZE_API ElementBuffer : public Buffer
	{
	public:
		ElementBuffer();
		~ElementBuffer();

		virtual void Create() override;

		void UploadData(std::vector<int>* data);

		virtual void Bind() override;
		virtual void UnBind() override;
	};

	class BLAZE_API FrameBuffer : public Buffer
	{
	public:
		FrameBuffer();
		~FrameBuffer();

		bool IsFrameBufferComplete();

		virtual void Create() override;

		virtual void Bind() override;
		virtual void UnBind() override;
	};
}