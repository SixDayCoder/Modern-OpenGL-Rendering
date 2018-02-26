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

			//��ȡ����ʱ��Ŀ¼
			static std::string GetCurrentDir();
			
			//�ж��Ƿ����ĳ���ļ���
			static bool IsExist(const std::string& strAbsoluteDirPath);

			//�����ļ���
			static void CreateDir(const std::string& strAbsoluteDirPath);

			//ɾ���ļ���
			static void RemoveDir(const std::string& strAbsoluteDirPath);

			//�����ļ�
			static void CreateNewFile(const std::string& strFullFilePath);

			//ɾ���ļ�
			static void RemoveFile(const std::string& strFullFilePath);

			static const std::string ShaderRoot;

			static const std::string Texture2DRoot;

		};
	}
}

#endif 