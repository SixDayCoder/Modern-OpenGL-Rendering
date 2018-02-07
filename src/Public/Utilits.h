#ifndef SIXDAY_UTILITIS_H
#define SIXDAY_UTILITIS_H

#include "Public\PublicDefine.h"

namespace sixday
{
	namespace utilits
	{

		class Timer
		{
		public:

			Timer()
			{
				CleanUp();
			}

			void CleanUp();

			double DeltaTime()const;

			double ElapsedTime()const;

			double Frequency()const;

			void StartClick();

			void Tick();

		private:

			time_type m_StartTime;
			time_type m_LastTime;
			time_type m_CurrentTime;
			microseconds m_DeltaTime;

			Timer(const Timer&) {}
			Timer& operator=(const Timer&) {}
		};


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