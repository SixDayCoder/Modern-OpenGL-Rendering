#ifndef SIXDAY_PUBLIC_DEFINE_H
#define SIXDAY_PUBLIC_DEFINE_H

#include <chrono>
#include <vector>
#include <map>

namespace sixday
{

	#define DOUBLE_ONE_MILLION 1000000.0
	#define PI 3.141592654
	#define PI_DIV_2 1.570796327
	#define PI_DIV_4 0.785398165

	using uint32 = unsigned int;
	using uint64 = unsigned long;
	using byte = unsigned char;
	using Guid = long long;

	using microseconds = std::chrono::microseconds;
	using milliseconds = std::chrono::milliseconds;
	using seconds = std::chrono::seconds;
	using time_type = std::chrono::time_point<std::chrono::high_resolution_clock, microseconds>;
}

#endif 
