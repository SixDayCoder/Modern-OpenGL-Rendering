#include "Utilits.h"

namespace sixday
{
	namespace utilits
	{
		double Timer::DeltaTime()const
		{
			return static_cast<double>(m_DeltaTime.count() / DOUBLE_ONE_MILLION);
		}

		double Timer::ElapsedTime()const
		{
			microseconds tp = m_CurrentTime.time_since_epoch() - m_StartTime.time_since_epoch();
			return static_cast<double>(tp.count() / DOUBLE_ONE_MILLION);
		}

		double Timer::Frequency()const
		{
			double delta = DeltaTime();
			if (delta <= 0.0)
			{
				return 0.0;
			}
			return 1.0 / delta;
		}

		void Timer::StartClick()
		{
			m_StartTime = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
			m_LastTime = m_StartTime;
		}

		void Timer::Tick()
		{
			m_CurrentTime = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
			m_DeltaTime = m_CurrentTime.time_since_epoch() - m_LastTime.time_since_epoch();
			m_LastTime = m_CurrentTime;
		}

		void Timer::CleanUp()
		{
			m_StartTime = time_type();
			m_LastTime = time_type();
			m_CurrentTime = time_type();
			m_DeltaTime = milliseconds();
		}


		/*=========================================================Utlits================================================================*/

		double Utilits::Radius2Angle(float fRadius)
		{
			return 180.0 / PI * fRadius;
		}

		double Utilits::Angle2Radius(float fAngle)
		{
			return PI / 180.0 * fAngle;
		}

		/*=========================================================Utlits================================================================*/
	}
}