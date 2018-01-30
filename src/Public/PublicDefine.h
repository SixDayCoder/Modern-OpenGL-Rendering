#ifndef SIXDAY_PUBLIC_DEFINE_H
#define SIXDAY_PUBLIC_DEFINE_H

#include <chrono>
#include <vector>
#include <map>

namespace sixday
{

	#define DOUBLE_ONE_MILLION 1000000.0

	using uint32 = unsigned int;
	using uint64 = unsigned long;
	using byte = unsigned char;


	using microseconds = std::chrono::microseconds;
	using milliseconds = std::chrono::milliseconds;
	using seconds = std::chrono::seconds;
	using time_type = std::chrono::time_point<std::chrono::high_resolution_clock, microseconds>;
}

#endif 
