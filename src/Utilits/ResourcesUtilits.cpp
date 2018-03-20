#include "Utilits\ResourcesUtilits.h"
#include "Utilits\FileUtilits.h"
#include <iostream>
#include <filesystem>

namespace sixday
{
	namespace utilits
	{
		ResourcesUtilits::ShaderResourcesMap ResourcesUtilits::ShaderMap;

		ResourcesUtilits::Texture2DResourcesMap ResourcesUtilits::Texture2DMap;

		void ResourcesUtilits::LoadShader(const std::string & name, const char * vShaderFile, const char * fShaderFile, const char * gShaderFile)
		{
		
			assert(vShaderFile);
			assert(fShaderFile);

			std::string vpath = FileUtiltis::ShaderRoot + vShaderFile;
			std::string fpath = FileUtiltis::ShaderRoot + fShaderFile;

			if (gShaderFile != nullptr)
			{
				std::string gpath = FileUtiltis::ShaderRoot + gShaderFile;
				Shader shader(vpath.c_str(), fpath.c_str(), gpath.c_str());
				ShaderMap.insert(std::make_pair(name, shader));
			}
			else
			{
				Shader shader(vpath.c_str(), fpath.c_str(), nullptr);
				ShaderMap.insert(std::make_pair(name, shader));
			}

		}

		sixday::render::Shader ResourcesUtilits::GetShader(const std::string & name)
		{
			auto it = ShaderMap.find(name);
			assert(it != ShaderMap.end());
			return it->second;
		}

		void ResourcesUtilits::LoadTexture2D(const std::string & name, const char * file)
		{
			assert(file);

			std::string path = FileUtiltis::Texture2DRoot + file;

			Texture2D texture;
			texture.LoadFromFile(path.c_str());
			Texture2DMap.insert(std::make_pair(name, texture));
		}

		sixday::render::Texture2D ResourcesUtilits::GetTexture2D(const std::string & name)
		{
			auto it = Texture2DMap.find(name);
			assert(it != Texture2DMap.end());
			return it->second;
		}
	}
}