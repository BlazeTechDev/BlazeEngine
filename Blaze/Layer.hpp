#pragma once

#include "Core.hpp"
#include "Event.hpp"

namespace Blaze
{
	class BLAZE_API Layer
	{
	public:
		Layer(const std::string& debugName = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {};
		virtual void OnDetach() {};
		virtual void OnUpdate() {};
		virtual void OnEvent(Event& event) {};

		inline const std::string& GetName() const { return m_DebugName; }

	protected:
		std::string m_DebugName;
	};
}