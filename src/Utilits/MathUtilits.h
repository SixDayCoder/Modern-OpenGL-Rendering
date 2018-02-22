#ifndef SIXDAY_MATHUTILITS_H
#define SIXDAY_MATHUTILITS_H


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