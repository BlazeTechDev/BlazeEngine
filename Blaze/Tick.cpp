#include "blzpch.hpp"
#include "Tick.hpp"

namespace Blaze
{
	int Tick::m_CurrentTick = 0;
	int Tick::m_CurrentTime = 0;

	bool Tick::IsTickFrame()
	{
		if (m_CurrentTime % 1/TicksPerSecond == 0)
		{
			return true;
		}

		return false;
	}

	void Tick::TickOnce(Timestep timeStep)
	{
		if (m_CurrentTick >= TicksPerSecond)
		{
			m_CurrentTick = 0;
		}
		if (m_CurrentTime >= 1)
		{
			m_CurrentTime = 0;
		}

		m_CurrentTime += timeStep.GetSeconds();
		
		if (IsTickFrame())
		{
			m_CurrentTick++;
		}
	}
}