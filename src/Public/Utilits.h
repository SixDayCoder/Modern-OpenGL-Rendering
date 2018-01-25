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

		class Timer
		{

		private:

			using time_type = std::chrono::time_point<std::chrono::high_resolution_clock, microseconds>;

		public:


			Timer()
			{
				Reset();
			}

			void Reset()
			{
				m_StartTime = time_type();
				m_LastTime = time_type();
				m_CurrentTime = time_type();
				m_DeltaTime = milliseconds();
			}

			double DeltaTime()const
			{
				return static_cast<double>(m_DeltaTime.count() / 1000000.0);
			}

			double ElapsedTime()const
			{
				microseconds tp = m_CurrentTime.time_since_epoch() - m_StartTime.time_since_epoch();
				return static_cast<double>(tp.count() / 1000000.0);
			}

			double Frequency()const
			{

			}


			void Start()
			{
				m_StartTime = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
				m_LastTime = m_StartTime;

			}

			void Tick()
			{
				m_CurrentTime = std::chrono::time_point_cast<microseconds>(std::chrono::high_resolution_clock::now());
				m_DeltaTime = m_CurrentTime.time_since_epoch() - m_LastTime.time_since_epoch();
				m_LastTime = m_CurrentTime;
			}

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