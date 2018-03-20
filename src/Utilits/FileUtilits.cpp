
#include "Utilits\FileUtilits.h"
#include <iostream>
#include <fstream>
#include <filesystem>


namespace sixday
{
	namespace utilits
	{

		const std::string FileUtiltis::ShaderRoot = std::tr2::sys::current_path().parent_path().parent_path().append("\\resources\\shader\\").string();

		const std::string FileUtiltis::Texture2DRoot = std::tr2::sys::current_path().parent_path().parent_path().append("\\resources\\image\\").string();

		const std::string FileUtiltis::ModelRoot = std::tr2::sys::current_path().parent_path().parent_path().append("\\resources\\model\\").string();

		std::string FileUtiltis::GetCurrentDir()
		{
			std::tr2::sys::path  path = std::tr2::sys::current_path();
			return path.string();
		}

		bool FileUtiltis::IsExist(const std::string & strAbsoluteDirPath)
		{
			std::tr2::sys::path path(strAbsoluteDirPath);
			return std::tr2::sys::exists(path);

		}
		void FileUtiltis::CreateDir(const std::string & strAbsoluteDirPath)
		{
			std::tr2::sys::path path(strAbsoluteDirPath);
			std::tr2::sys::create_directories(path);
		}

		void FileUtiltis::RemoveDir(const std::string & strAbsoluteDirPath)
		{
			std::tr2::sys::path path(strAbsoluteDirPath);
			std::tr2::sys::remove_all(path);
		}

		void FileUtiltis::CreateNewFile(const std::string & strFullFilePath)
		{
			std::ofstream file;
			file.open(strFullFilePath, std::ios::out);
			file.close();
		}


		void FileUtiltis::RemoveFile(const std::string & strFullFilePath)
		{
			std::tr2::sys::path path(strFullFilePath);
			std::tr2::sys::remove(path);
		}

	}
}