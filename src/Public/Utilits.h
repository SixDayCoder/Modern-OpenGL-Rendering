#ifndef SIXDAY_UTILITIS_H
#define SIXDAY_UTILITIS_H

#include "Public\PublicDefine.h"

namespace sixday
{
	namespace utilits
	{

		class Utilits
		{
		public:

			static double Radius2Angle(float fRadius);

			static double Angle2Radius(float fAngle);

			static Guid GetNextGuid();

		};

	}
}

#endif