#include "Utilits\LogUtilits.h"
#include "Utilits\FileUtilits.h"
#include "Public\PublicDefine.h"
#include <ctime>
#include <filesystem>

namespace sixday
{
	namespace utilits
	{
		void LogUtilits::Assert(bool bCondition, const std::string & message)
		{
			if (bCondition)
			{
				return;
			}

			LogError(message);
		}

		void LogUtilits::LogError(const std::string & error)
		{

		}
	}
}

