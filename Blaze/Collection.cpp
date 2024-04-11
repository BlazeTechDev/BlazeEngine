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
		for (Entity* entity : m_Entities)
		{
			delete entity;
		}

		for (Component* component : m_Components)
		{
			delete component;
		}
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
		Graphics::BindSceneViewportFrameBuffer();

		for (Component* component : m_Components)
		{
			BLZ_CORE_INFO("drawing collection {0}", m_Name);
		}

		Graphics::UnBindSceneViewportFrameBuffer();
	}
}