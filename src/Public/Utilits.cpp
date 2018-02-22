#include "Utilits.h"

namespace sixday
{
	namespace utilits
	{

		double Utilits::Radius2Angle(float fRadius)
		{
			return 180.0 / PI * fRadius;
		}

		double Utilits::Angle2Radius(float fAngle)
		{
			return PI / 180.0 * fAngle;
		}

		Guid Utilits::GetNextGuid()
		{
			time_type now = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
			return now.time_since_epoch().count();
		}

		void Utilits::Assert(bool bCondition, const char * message)
		{
			if (bCondition)
			{
				return;
			}


		}

	}
}