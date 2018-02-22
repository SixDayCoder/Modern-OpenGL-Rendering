#ifndef SIXDAY_MATH_UTILITS_H_
#define SIXDAY_MATH_UTILITS_H_


#include "Public\PublicDefine.h"

namespace sixday
{
	namespace utilits
	{
		class MathUtilits
		{
		public:

			static const float PI;

			static const float PI_DIV_2;

			static const float PI_DIV_4;

			static float Radius2Angle(float fRadius);

			static float Angle2Radius(float fAngle);
		};
	}
}


#endif