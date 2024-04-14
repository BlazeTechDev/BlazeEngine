#pragma once

#include "Core.hpp"

#include <glm.hpp>

namespace Blaze
{
	struct BLAZE_API CameraGraphicalData
	{
		glm::vec3 position;
		glm::vec3 rotation;
	};

	class BLAZE_API Camera
	{
	public:
		Camera();

		CameraGraphicalData& GetGraphicalData() { return m_Data; }

	private:
		CameraGraphicalData m_Data;
	};
}