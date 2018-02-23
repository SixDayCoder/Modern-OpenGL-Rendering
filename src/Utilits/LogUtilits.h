#ifndef  SIXDAY_LOG_UTILITS_H
#define  SIXDAY_LOG_UTILITS_H

#include <string>

namespace sixday
{
	namespace utilits
	{
		class LogUtilits
		{
			static void Assert(bool bCondition, const std::string& message);

			static void LogError(const std::string& error);
		};
	}
}

#endif // ! SIXDAY_LOG_UTILITS_H
