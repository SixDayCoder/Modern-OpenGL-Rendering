#ifndef SIXDAY_UTILITIS_H
#define SIXDAY_UTILITIS_H

#include <chrono>

namespace sixday
{
	namespace utilits
	{

		using microseconds = std::chrono::microseconds;
		using milliseconds = std::chrono::milliseconds;
		using seconds = std::chrono::seconds;
		using time_type = std::chrono::time_point<std::chrono::high_resolution_clock, microseconds>;

		class Timer
		{
			#define DOUBLE_ONE_MILLION 1000000.0

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
	}
}

#endif