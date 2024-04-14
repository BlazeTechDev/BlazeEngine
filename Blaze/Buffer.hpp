#pragma once

#include "Core.hpp"
#include "Log.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

namespace Blaze
{
	enum class BLAZE_API BlazeDataType
	{
		BLZ_FLOAT,
		BLZ_INT,
		BLZ_DOUBLE,
		BLZ_BOOL
	};

	static uint32_t ShaderDataTypeSize(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Bool: return 1;
		case ShaderDataType::Float: return 4;
		case ShaderDataType::Float2: return 4 * 2;
		case ShaderDataType::Float3: return 4 * 3;
		case ShaderDataType::Float4: return 4 * 4;
		case ShaderDataType::Int: return 4;
		case ShaderDataType::Int2: return 4;
		case ShaderDataType::Int3: return 4;
		case ShaderDataType::Int4: return 4;
		case ShaderDataType::Double: return 4;
		case ShaderDataType::Double2: return 4;
		case ShaderDataType::Double3: return 4;
		case ShaderDataType::Double4: return 4;
		case ShaderDataType::Mat3: return 4 * 3 * 3;
		case ShaderDataType::Mat4: return 4 * 4 * 4;
		}

		BLZ_CORE_ASSERT(false, "Unkown ShaderDataType type");
		return 0;
	}

	struct BLAZE_API BufferElement
	{
	public:
		std::string Name;
		ShaderDataType Type;
		uint32_t Offset;
		uint32_t Size;
		bool Normalized;

		BufferElement(ShaderDataType type, const std::string& name) : Type(type), Name(name), Offset(0), Size(ShaderDataTypeSize(type)), Normalized(false) {};

		uint32_t GetElementCount() const
		{
			switch (Type)
			{
			case ShaderDataType::Bool: return 1;
			case ShaderDataType::Float: return 1;
			case ShaderDataType::Float2: return 2;
			case ShaderDataType::Float3: return 3;
			case ShaderDataType::Float4: return 4;
			case ShaderDataType::Int: return 1;
			case ShaderDataType::Int2: return 2;
			case ShaderDataType::Int3: return 3;
			case ShaderDataType::Int4: return 4;
			case ShaderDataType::Double: return 1;
			case ShaderDataType::Double2: return 2;
			case ShaderDataType::Double3: return 3;
			case ShaderDataType::Double4: return 4;
			case ShaderDataType::Mat3: return 3 * 3;
			case ShaderDataType::Mat4: return 4 * 4;
			}
		}
	};

	inline BlazeDataType ShaderDataTypeToBlazeDataType(ShaderDataType type)
	{
		switch (type)
		{
		case ShaderDataType::Bool: return BlazeDataType::BLZ_BOOL;
		case ShaderDataType::Float: return BlazeDataType::BLZ_FLOAT;
		case ShaderDataType::Float2: return BlazeDataType::BLZ_FLOAT;
		case ShaderDataType::Float3: return BlazeDataType::BLZ_FLOAT;
		case ShaderDataType::Float4: return BlazeDataType::BLZ_FLOAT;
		case ShaderDataType::Int: return BlazeDataType::BLZ_INT;
		case ShaderDataType::Int2: return BlazeDataType::BLZ_INT;
		case ShaderDataType::Int3: return BlazeDataType::BLZ_INT;
		case ShaderDataType::Int4: return BlazeDataType::BLZ_INT;
		case ShaderDataType::Double: return BlazeDataType::BLZ_DOUBLE;
		case ShaderDataType::Double2: return BlazeDataType::BLZ_DOUBLE;
		case ShaderDataType::Double3: return BlazeDataType::BLZ_DOUBLE;
		case ShaderDataType::Double4: return BlazeDataType::BLZ_DOUBLE;
		case ShaderDataType::Mat3: return BlazeDataType::BLZ_FLOAT;
		case ShaderDataType::Mat4: return BlazeDataType::BLZ_FLOAT;
		}
	}

	struct BLAZE_API BufferLayout
	{
	public:
		BufferLayout(const std::initializer_list<BufferElement>& elements) : m_Elements(elements) { CalculateOffsetsAndStride(); };

		inline const std::vector<BufferElement>& GetElements() const { return m_Elements; }
		inline uint32_t GetStride() const { return m_Stride; };

		std::vector<BufferElement>::iterator begin() { return m_Elements.begin(); }
		std::vector<BufferElement>::iterator end() { return m_Elements.end(); }
		
	private:
		void CalculateOffsetsAndStride()
		{
			uint32_t offset = 0;
			m_Stride = 0;
			for (BufferElement& element : m_Elements)
			{
				element.Offset = offset;
				offset += element.Size;
				m_Stride += element.Size;
			}
		}

		std::vector<BufferElement> m_Elements;
		uint32_t m_Stride;
	};

	class BLAZE_API Buffer
	{
	public:
		Buffer() { m_Id = 0; };
		~Buffer() {};

		virtual void Create() {};

		virtual void Bind() const {};
		virtual void UnBind() const {};

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

		void UploadData(const std::vector<float>* data);

		virtual void Bind() const override;
		virtual void UnBind() const override;

		const std::vector<float>* GetData() { return m_Data; }
		int GetCount() { return m_Data->size(); }

		const BufferLayout* GetLayout() const { return m_Layout; }
		void SetLayout(BufferLayout* layout) { m_Layout = layout; }

	private:
		BufferLayout* m_Layout;
		const std::vector<float>* m_Data;
	};

	class BLAZE_API IndexBuffer : public Buffer
	{
	public:
		IndexBuffer();
		~IndexBuffer();

		virtual void Create() override;

		void UploadData(const std::vector<int>* data);
		int GetCount() { return m_Data->size(); }

		const std::vector<int>* GetData() { return m_Data; }

		virtual void Bind() const override;
		virtual void UnBind() const override;

	private:
		const std::vector<int>* m_Data;
	};

	class BLAZE_API VertexArray
	{
	public:
		VertexArray();

		void Create();

		static void CreateAttributePointer(int index, int size, BlazeDataType data_type, bool normalized, uint32_t stride, uint32_t offset);

		void Bind() const;
		void UnBind() const;

		void AddVertexBuffer(VertexBuffer* vertexBuffer);
		void SetIndexBuffer(IndexBuffer* IndexBuffer);

		std::vector<VertexBuffer*> GetVertexBuffers() { return m_VertexBuffers; }
		IndexBuffer* GetIndexBuffer() { return m_IndexBuffer; }

		static void Enable(int indeex);
		static void Disable(int index);

		unsigned int GetID() { return m_Id; }

	private:
		std::vector<VertexBuffer*> m_VertexBuffers;
		IndexBuffer* m_IndexBuffer;

		unsigned int m_Id;
	};
}