#include "Utilits\MathUtilits.h"

namespace sixday
{
	namespace utilits
	{
		const float MathUtilits::PI = 3.141592654f;

		const float MathUtilits::PI_DIV_2 = 1.570796327f;

		const float MathUtilits::PI_DIV_4 = 0.785398165f;

		float MathUtilits::Radius2Angle(float fRadius)
		{
			return 180.0f / PI * fRadius;
		}

		float MathUtilits::Angle2Radius(float fAngle)
		{
			return PI / 180.0f * fAngle;
		}
	}
}