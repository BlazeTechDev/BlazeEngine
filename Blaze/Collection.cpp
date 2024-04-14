#include "blzpch.hpp"
#include "Collection.hpp"

#include "Log.hpp"
#include "Graphics.hpp"

namespace Blaze
{
	Collection::Collection(std::string name)
	{
		m_Name = name;
	}

	Collection::~Collection()
	{

	}

	void Collection::Start()
	{

	}

	void Collection::EditorTick()
	{
		DrawCollection();
	}

	void Collection::Tick()
	{
		DrawCollection();
	}

	void Collection::DrawCollection()
	{

	}
}