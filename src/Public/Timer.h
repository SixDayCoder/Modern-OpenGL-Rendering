#ifndef SIXDAY_TIMER_H
#define SIXDAY_TIMER_H

#include "Public\Utilits.h"


namespace sixday
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

		void Stop();

		void Start();

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




#endif 
