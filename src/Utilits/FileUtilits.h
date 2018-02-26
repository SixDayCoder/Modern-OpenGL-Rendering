#ifndef SIXDAY_FILE_UTILITS_H_
#define SIXDAY_FILE_UTILITS_H_

#include "Public\PublicDefine.h"
#include <string>

namespace sixday
{
	namespace utilits
	{
		class FileUtiltis
		{
		public:

			//获取运行时的目录
			static std::string GetCurrentDir();
			
			//判断是否存在某个文件夹
			static bool IsExist(const std::string& strAbsoluteDirPath);

			//创建文件夹
			static void CreateDir(const std::string& strAbsoluteDirPath);

			//删除文件夹
			static void RemoveDir(const std::string& strAbsoluteDirPath);

			//创建文件
			static void CreateNewFile(const std::string& strFullFilePath);

			//删除文件
			static void RemoveFile(const std::string& strFullFilePath);

			static const std::string ShaderRoot;

			static const std::string Texture2DRoot;

		};
	}
}

#endif 