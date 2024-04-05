#pragma once

#include "Event.hpp"

namespace Blaze
{
	class BLAZE_API ApplicationTickEvent : public Event
	{
	public:
		ApplicationTickEvent() {}

		EVENT_CLASS_TYPE(ApplicationTick)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLAZE_API ApplicationUpdateEvent : public Event
	{
	public:
		ApplicationUpdateEvent() {}

		EVENT_CLASS_TYPE(ApplicationUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class BLAZE_API ApplicationRenderEvent : public Event
	{
	public:
		ApplicationRenderEvent() {}

		EVENT_CLASS_TYPE(ApplicationRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}