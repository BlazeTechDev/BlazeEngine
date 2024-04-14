#pragma once

#include "Core.hpp"
#include "Time.hpp"

namespace Blaze
{
	class BLAZE_API Tick
	{
	public:
		static const int TicksPerSecond = 60;

		static bool IsTickFrame();
		static void TickOnce(Timestep timeStep);

		static const int GetTick() { return m_CurrentTick; }
		static const int GetTickTime() { return m_CurrentTime; }

	private:
		static int m_CurrentTick;
		static int m_CurrentTime;
	};
}