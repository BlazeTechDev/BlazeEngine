#include "blzpch.hpp"
#include "Camera.hpp"

namespace Blaze
{
	Camera::Camera()
	{
		m_Data.position = glm::vec3(0, 0, 0);
		m_Data.rotation = glm::vec3(0, 0, 0);
	}
}